const path = require('path')
const fs = require('fs')
const chalk = require('chalk')
const CMAFP_ENGINE = require('../cmafp.js')

const log = (msg, ...args) => {
  console.log(`[Node]: ${chalk.yellow(msg)}`, ...args)
}
const space = () => console.log('\n\n')

/** @type {(val: number) => void} */
const uint8AsHex = val => {
  const binaryStr = val.toString(16);
  return binaryStr.padStart(2, '0')
}

/** @type {(val: number) => void} */
const uint8AsBinary = val => {
  const binaryStr = val.toString(2);
  return binaryStr.padStart(8, '0')
}

CMAFP_ENGINE.onRuntimeInitialized = function () {
  // Visualize current WASM runtime heap size
  //log(`CMAFP RUNTIME CHUNKS SIZE: ${CMAFP_ENGINE.logHeapSize()}`)

  // Load file into buffer
  const fileBuffer = fs.readFileSync(path.resolve(__dirname, 'sample/video/avc1/init.mp4'))
  log(`Local file read with buffer length: ${fileBuffer.length}`)

  // Create file with returned ID
  const fileName = 'cosmos_init'
  const fileId = CMAFP_ENGINE.createFile(fileName, fileBuffer.length)

  space()
  log(`Started file: ${fileName}-${fileId}\n`)

  // Start appending chunks of UInt8 values
  for (let i = 0; i < fileBuffer.length; i++) {
    const bufferVal = fileBuffer.readUInt8(i);
    CMAFP_ENGINE.appendTo(fileId, bufferVal);

    // Verbose
    // Compare sample set of values
    //if (i > (fileBuffer.length - 10)) {
    //  const hexRep = `Hex${i}[0x${uint8AsHex(bufferVal)}]`
    //  const intRep = `Int${i}[${bufferVal}]`
    //  log(`${hexRep}\t${intRep}\n`)
    //}`
  }

  const fileResult = CMAFP_ENGINE.closeFile(fileId);
  log(`File Created: `, chalk.magenta(fileResult));

  space();

  log(`Parsing header: ${fileName}`)
  const headerData = CMAFP_ENGINE.parseHeader(fileId)

  console.log(JSON.stringify(JSON.parse(headerData), null, 2))
  //log(`CMAFP RUNTIME CHUNKS SIZE: ${CMAFP_ENGINE.logHeapSize()}`)
}
