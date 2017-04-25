// Auto-generated. Do not edit!

// (in-package estimate_interest.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let PersonInfo = require('./PersonInfo.js');

//-----------------------------------------------------------

class PersonsArray {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.persons = null;
    }
    else {
      if (initObj.hasOwnProperty('persons')) {
        this.persons = initObj.persons
      }
      else {
        this.persons = [];
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type PersonsArray
    // Serialize message field [persons]
    // Serialize the length for message field [persons]
    bufferOffset = _serializer.uint32(obj.persons.length, buffer, bufferOffset);
    obj.persons.forEach((val) => {
      bufferOffset = PersonInfo.serialize(val, buffer, bufferOffset);
    });
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type PersonsArray
    let len;
    let data = new PersonsArray(null);
    // Deserialize message field [persons]
    // Deserialize array length for message field [persons]
    len = _deserializer.uint32(buffer, bufferOffset);
    data.persons = new Array(len);
    for (let i = 0; i < len; ++i) {
      data.persons[i] = PersonInfo.deserialize(buffer, bufferOffset)
    }
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += 34 * object.persons.length;
    return length + 4;
  }

  static datatype() {
    // Returns string type for a message object
    return 'estimate_interest/PersonsArray';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'f57b15010fa4594dd3c7a208c2ed5847';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    PersonInfo[] persons
    ================================================================================
    MSG: estimate_interest/PersonInfo
    uint8 id
    uint8 status
    time stamp
    float64 x
    float64 y
    float64 z
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new PersonsArray(null);
    if (msg.persons !== undefined) {
      resolved.persons = new Array(msg.persons.length);
      for (let i = 0; i < resolved.persons.length; ++i) {
        resolved.persons[i] = PersonInfo.Resolve(msg.persons[i]);
      }
    }
    else {
      resolved.persons = []
    }

    return resolved;
    }
};

module.exports = PersonsArray;
