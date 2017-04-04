// Auto-generated. Do not edit!

// (in-package trollnode.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class Expression {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.speech = null;
      this.expression = null;
      this.look = null;
    }
    else {
      if (initObj.hasOwnProperty('speech')) {
        this.speech = initObj.speech
      }
      else {
        this.speech = '';
      }
      if (initObj.hasOwnProperty('expression')) {
        this.expression = initObj.expression
      }
      else {
        this.expression = '';
      }
      if (initObj.hasOwnProperty('look')) {
        this.look = initObj.look
      }
      else {
        this.look = '';
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type Expression
    // Serialize message field [speech]
    bufferOffset = _serializer.string(obj.speech, buffer, bufferOffset);
    // Serialize message field [expression]
    bufferOffset = _serializer.string(obj.expression, buffer, bufferOffset);
    // Serialize message field [look]
    bufferOffset = _serializer.string(obj.look, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type Expression
    let len;
    let data = new Expression(null);
    // Deserialize message field [speech]
    data.speech = _deserializer.string(buffer, bufferOffset);
    // Deserialize message field [expression]
    data.expression = _deserializer.string(buffer, bufferOffset);
    // Deserialize message field [look]
    data.look = _deserializer.string(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += object.speech.length;
    length += object.expression.length;
    length += object.look.length;
    return length + 12;
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

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new Expression(null);
    if (msg.speech !== undefined) {
      resolved.speech = msg.speech;
    }
    else {
      resolved.speech = ''
    }

    if (msg.expression !== undefined) {
      resolved.expression = msg.expression;
    }
    else {
      resolved.expression = ''
    }

    if (msg.look !== undefined) {
      resolved.look = msg.look;
    }
    else {
      resolved.look = ''
    }

    return resolved;
    }
};

module.exports = Expression;
