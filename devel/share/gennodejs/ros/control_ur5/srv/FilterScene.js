// Auto-generated. Do not edit!

// (in-package control_ur5.srv)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let std_msgs = _finder('std_msgs');

//-----------------------------------------------------------


//-----------------------------------------------------------

class FilterSceneRequest {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.pointcloud_topic = null;
      this.image_topic = null;
    }
    else {
      if (initObj.hasOwnProperty('pointcloud_topic')) {
        this.pointcloud_topic = initObj.pointcloud_topic
      }
      else {
        this.pointcloud_topic = new std_msgs.msg.String();
      }
      if (initObj.hasOwnProperty('image_topic')) {
        this.image_topic = initObj.image_topic
      }
      else {
        this.image_topic = new std_msgs.msg.String();
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type FilterSceneRequest
    // Serialize message field [pointcloud_topic]
    bufferOffset = std_msgs.msg.String.serialize(obj.pointcloud_topic, buffer, bufferOffset);
    // Serialize message field [image_topic]
    bufferOffset = std_msgs.msg.String.serialize(obj.image_topic, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type FilterSceneRequest
    let len;
    let data = new FilterSceneRequest(null);
    // Deserialize message field [pointcloud_topic]
    data.pointcloud_topic = std_msgs.msg.String.deserialize(buffer, bufferOffset);
    // Deserialize message field [image_topic]
    data.image_topic = std_msgs.msg.String.deserialize(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.String.getMessageSize(object.pointcloud_topic);
    length += std_msgs.msg.String.getMessageSize(object.image_topic);
    return length;
  }

  static datatype() {
    // Returns string type for a service object
    return 'control_ur5/FilterSceneRequest';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '69e46d0658fdec66c7fd92ae3c8381f0';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    std_msgs/String pointcloud_topic
    std_msgs/String image_topic
    
    ================================================================================
    MSG: std_msgs/String
    string data
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new FilterSceneRequest(null);
    if (msg.pointcloud_topic !== undefined) {
      resolved.pointcloud_topic = std_msgs.msg.String.Resolve(msg.pointcloud_topic)
    }
    else {
      resolved.pointcloud_topic = new std_msgs.msg.String()
    }

    if (msg.image_topic !== undefined) {
      resolved.image_topic = std_msgs.msg.String.Resolve(msg.image_topic)
    }
    else {
      resolved.image_topic = new std_msgs.msg.String()
    }

    return resolved;
    }
};

class FilterSceneResponse {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.finished = null;
    }
    else {
      if (initObj.hasOwnProperty('finished')) {
        this.finished = initObj.finished
      }
      else {
        this.finished = new std_msgs.msg.Empty();
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type FilterSceneResponse
    // Serialize message field [finished]
    bufferOffset = std_msgs.msg.Empty.serialize(obj.finished, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type FilterSceneResponse
    let len;
    let data = new FilterSceneResponse(null);
    // Deserialize message field [finished]
    data.finished = std_msgs.msg.Empty.deserialize(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 0;
  }

  static datatype() {
    // Returns string type for a service object
    return 'control_ur5/FilterSceneResponse';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '18521540d6a8ef1c5bbd2580b55486c5';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    std_msgs/Empty finished
    
    ================================================================================
    MSG: std_msgs/Empty
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new FilterSceneResponse(null);
    if (msg.finished !== undefined) {
      resolved.finished = std_msgs.msg.Empty.Resolve(msg.finished)
    }
    else {
      resolved.finished = new std_msgs.msg.Empty()
    }

    return resolved;
    }
};

module.exports = {
  Request: FilterSceneRequest,
  Response: FilterSceneResponse,
  md5sum() { return 'ea94d240c31365a6cbd92625f469bbdc'; },
  datatype() { return 'control_ur5/FilterScene'; }
};
