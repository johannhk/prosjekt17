// Auto-generated. Do not edit!

// (in-package speech_processing.msg)


"use strict";

let _serializer = require('../base_serialize.js');
let _deserializer = require('../base_deserialize.js');
let _finder = require('../find.js');

//-----------------------------------------------------------

class Expression {
  constructor() {
    this.speech = '';
    this.expression = '';
  }

  static serialize(obj, bufferInfo) {
    // Serializes a message object of type Expression
    // Serialize message field [speech]
    bufferInfo = _serializer.string(obj.speech, bufferInfo);
    // Serialize message field [expression]
    bufferInfo = _serializer.string(obj.expression, bufferInfo);
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
    return {
      data: data,
      buffer: buffer
    }
  }

  static datatype() {
    // Returns string type for a message object
    return 'speech_processing/Expression';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '64c25de9407ff13a659a42faaadb6ea1';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    string speech		#The troll will say this out loud. Write normal english.
    string expression 	#shortform for the expression, like angry, smile, etc. 
    
    
    `;
  }

};

module.exports = Expression;
