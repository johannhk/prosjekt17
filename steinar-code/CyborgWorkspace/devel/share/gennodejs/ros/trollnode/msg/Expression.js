// Auto-generated. Do not edit!

// (in-package trollnode.msg)


"use strict";

let _serializer = require('../base_serialize.js');
let _deserializer = require('../base_deserialize.js');
let _finder = require('../find.js');

//-----------------------------------------------------------

class Expression {
  constructor() {
    this.speech = '';
    this.expression = '';
    this.look = '';
  }

  static serialize(obj, bufferInfo) {
    // Serializes a message object of type Expression
    // Serialize message field [speech]
    bufferInfo = _serializer.string(obj.speech, bufferInfo);
    // Serialize message field [expression]
    bufferInfo = _serializer.string(obj.expression, bufferInfo);
    // Serialize message field [look]
    bufferInfo = _serializer.string(obj.look, bufferInfo);
    return bufferInfo;
  }

  static deserialize(buffer) {
    //deserializes a message object of type Expression
    let tmp;
    let len;
    let data = new Expression();
    // Deserialize message field [speech]
    tmp = _deserializer.string(buffer);
    data.speech = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [expression]
    tmp = _deserializer.string(buffer);
    data.expression = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [look]
    tmp = _deserializer.string(buffer);
    data.look = tmp.data;
    buffer = tmp.buffer;
    return {
      data: data,
      buffer: buffer
    }
  }

  static datatype() {
    // Returns string type for a message object
    return 'trollnode/Expression';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'c4b0b66f4e8edc3a85581ccec469d88c';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    string speech		#The troll will say this out loud. Write normal english.
    string expression 	#shortform for the expression, like angry, smile, etc. 
    string look			#where the troll should look. left, right, up, down
    
    `;
  }

};

module.exports = Expression;
