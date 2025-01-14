; Auto-generated. Do not edit!


(cl:in-package control_ur5-srv)


;//! \htmlinclude FilterScene-request.msg.html

(cl:defclass <FilterScene-request> (roslisp-msg-protocol:ros-message)
  ((pointcloud_topic
    :reader pointcloud_topic
    :initarg :pointcloud_topic
    :type std_msgs-msg:String
    :initform (cl:make-instance 'std_msgs-msg:String))
   (image_topic
    :reader image_topic
    :initarg :image_topic
    :type std_msgs-msg:String
    :initform (cl:make-instance 'std_msgs-msg:String)))
)

(cl:defclass FilterScene-request (<FilterScene-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <FilterScene-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'FilterScene-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name control_ur5-srv:<FilterScene-request> is deprecated: use control_ur5-srv:FilterScene-request instead.")))

(cl:ensure-generic-function 'pointcloud_topic-val :lambda-list '(m))
(cl:defmethod pointcloud_topic-val ((m <FilterScene-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader control_ur5-srv:pointcloud_topic-val is deprecated.  Use control_ur5-srv:pointcloud_topic instead.")
  (pointcloud_topic m))

(cl:ensure-generic-function 'image_topic-val :lambda-list '(m))
(cl:defmethod image_topic-val ((m <FilterScene-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader control_ur5-srv:image_topic-val is deprecated.  Use control_ur5-srv:image_topic instead.")
  (image_topic m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <FilterScene-request>) ostream)
  "Serializes a message object of type '<FilterScene-request>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'pointcloud_topic) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'image_topic) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <FilterScene-request>) istream)
  "Deserializes a message object of type '<FilterScene-request>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'pointcloud_topic) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'image_topic) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<FilterScene-request>)))
  "Returns string type for a service object of type '<FilterScene-request>"
  "control_ur5/FilterSceneRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'FilterScene-request)))
  "Returns string type for a service object of type 'FilterScene-request"
  "control_ur5/FilterSceneRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<FilterScene-request>)))
  "Returns md5sum for a message object of type '<FilterScene-request>"
  "ea94d240c31365a6cbd92625f469bbdc")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'FilterScene-request)))
  "Returns md5sum for a message object of type 'FilterScene-request"
  "ea94d240c31365a6cbd92625f469bbdc")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<FilterScene-request>)))
  "Returns full string definition for message of type '<FilterScene-request>"
  (cl:format cl:nil "std_msgs/String pointcloud_topic~%std_msgs/String image_topic~%~%================================================================================~%MSG: std_msgs/String~%string data~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'FilterScene-request)))
  "Returns full string definition for message of type 'FilterScene-request"
  (cl:format cl:nil "std_msgs/String pointcloud_topic~%std_msgs/String image_topic~%~%================================================================================~%MSG: std_msgs/String~%string data~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <FilterScene-request>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'pointcloud_topic))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'image_topic))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <FilterScene-request>))
  "Converts a ROS message object to a list"
  (cl:list 'FilterScene-request
    (cl:cons ':pointcloud_topic (pointcloud_topic msg))
    (cl:cons ':image_topic (image_topic msg))
))
;//! \htmlinclude FilterScene-response.msg.html

(cl:defclass <FilterScene-response> (roslisp-msg-protocol:ros-message)
  ((finished
    :reader finished
    :initarg :finished
    :type std_msgs-msg:Empty
    :initform (cl:make-instance 'std_msgs-msg:Empty)))
)

(cl:defclass FilterScene-response (<FilterScene-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <FilterScene-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'FilterScene-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name control_ur5-srv:<FilterScene-response> is deprecated: use control_ur5-srv:FilterScene-response instead.")))

(cl:ensure-generic-function 'finished-val :lambda-list '(m))
(cl:defmethod finished-val ((m <FilterScene-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader control_ur5-srv:finished-val is deprecated.  Use control_ur5-srv:finished instead.")
  (finished m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <FilterScene-response>) ostream)
  "Serializes a message object of type '<FilterScene-response>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'finished) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <FilterScene-response>) istream)
  "Deserializes a message object of type '<FilterScene-response>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'finished) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<FilterScene-response>)))
  "Returns string type for a service object of type '<FilterScene-response>"
  "control_ur5/FilterSceneResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'FilterScene-response)))
  "Returns string type for a service object of type 'FilterScene-response"
  "control_ur5/FilterSceneResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<FilterScene-response>)))
  "Returns md5sum for a message object of type '<FilterScene-response>"
  "ea94d240c31365a6cbd92625f469bbdc")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'FilterScene-response)))
  "Returns md5sum for a message object of type 'FilterScene-response"
  "ea94d240c31365a6cbd92625f469bbdc")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<FilterScene-response>)))
  "Returns full string definition for message of type '<FilterScene-response>"
  (cl:format cl:nil "std_msgs/Empty finished~%~%================================================================================~%MSG: std_msgs/Empty~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'FilterScene-response)))
  "Returns full string definition for message of type 'FilterScene-response"
  (cl:format cl:nil "std_msgs/Empty finished~%~%================================================================================~%MSG: std_msgs/Empty~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <FilterScene-response>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'finished))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <FilterScene-response>))
  "Converts a ROS message object to a list"
  (cl:list 'FilterScene-response
    (cl:cons ':finished (finished msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'FilterScene)))
  'FilterScene-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'FilterScene)))
  'FilterScene-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'FilterScene)))
  "Returns string type for a service object of type '<FilterScene>"
  "control_ur5/FilterScene")