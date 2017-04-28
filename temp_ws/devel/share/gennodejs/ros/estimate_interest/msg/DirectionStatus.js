// Auto-generated. Do not edit!

// (in-package estimate_interest.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class DirectionStatus {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.direction = null;
      this.interested = null;
    }
    else {
      if (initObj.hasOwnProperty('direction')) {
        this.direction = initObj.direction
      }
      else {
        this.direction = '';
      }
      if (initObj.hasOwnProperty('interested')) {
        this.interested = initObj.interested
      }
      else {
        this.interested = false;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type DirectionStatus
    // Serialize message field [direction]
    bufferOffset = _serializer.string(obj.direction, buffer, bufferOffset);
    // Serialize message field [interested]
    bufferOffset = _serializer.bool(obj.interested, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type DirectionStatus
    let len;
    let data = new DirectionStatus(null);
    // Deserialize message field [direction]
    data.direction = _deserializer.string(buffer, bufferOffset);
    // Deserialize message field [interested]
    data.interested = _deserializer.bool(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += object.direction.length;
    return length + 5;
  }

  static datatype() {
    // Returns string type for a message object
    return 'estimate_interest/DirectionStatus';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'a5dd941b461c18d19ca708608d53c0ad';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    string direction
    bool interested
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new DirectionStatus(null);
    if (msg.direction !== undefined) {
      resolved.direction = msg.direction;
    }
    else {
      resolved.direction = ''
    }

    if (msg.interested !== undefined) {
      resolved.interested = msg.interested;
    }
    else {
      resolved.interested = false
    }

    return resolved;
    }
};

module.exports = DirectionStatus;
