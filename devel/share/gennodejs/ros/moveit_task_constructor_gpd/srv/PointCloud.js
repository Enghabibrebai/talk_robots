// Auto-generated. Do not edit!

// (in-package moveit_task_constructor_gpd.srv)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------


//-----------------------------------------------------------

class PointCloudRequest {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.cloud_file = null;
    }
    else {
      if (initObj.hasOwnProperty('cloud_file')) {
        this.cloud_file = initObj.cloud_file
      }
      else {
        this.cloud_file = '';
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type PointCloudRequest
    // Serialize message field [cloud_file]
    bufferOffset = _serializer.string(obj.cloud_file, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type PointCloudRequest
    let len;
    let data = new PointCloudRequest(null);
    // Deserialize message field [cloud_file]
    data.cloud_file = _deserializer.string(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += _getByteLength(object.cloud_file);
    return length + 4;
  }

  static datatype() {
    // Returns string type for a service object
    return 'moveit_task_constructor_gpd/PointCloudRequest';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '94645eea953657df61f8fb2e51049aaa';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    # Request saving depth and rgb images
    # Input is file names to save them as
    string cloud_file
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new PointCloudRequest(null);
    if (msg.cloud_file !== undefined) {
      resolved.cloud_file = msg.cloud_file;
    }
    else {
      resolved.cloud_file = ''
    }

    return resolved;
    }
};

class PointCloudResponse {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
    }
    else {
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type PointCloudResponse
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type PointCloudResponse
    let len;
    let data = new PointCloudResponse(null);
    return data;
  }

  static getMessageSize(object) {
    return 0;
  }

  static datatype() {
    // Returns string type for a service object
    return 'moveit_task_constructor_gpd/PointCloudResponse';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'd41d8cd98f00b204e9800998ecf8427e';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new PointCloudResponse(null);
    return resolved;
    }
};

module.exports = {
  Request: PointCloudRequest,
  Response: PointCloudResponse,
  md5sum() { return '94645eea953657df61f8fb2e51049aaa'; },
  datatype() { return 'moveit_task_constructor_gpd/PointCloud'; }
};
