; Auto-generated. Do not edit!


(cl:in-package moveit_task_constructor_gpd-srv)


;//! \htmlinclude PointCloud-request.msg.html

(cl:defclass <PointCloud-request> (roslisp-msg-protocol:ros-message)
  ((cloud_file
    :reader cloud_file
    :initarg :cloud_file
    :type cl:string
    :initform ""))
)

(cl:defclass PointCloud-request (<PointCloud-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <PointCloud-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'PointCloud-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name moveit_task_constructor_gpd-srv:<PointCloud-request> is deprecated: use moveit_task_constructor_gpd-srv:PointCloud-request instead.")))

(cl:ensure-generic-function 'cloud_file-val :lambda-list '(m))
(cl:defmethod cloud_file-val ((m <PointCloud-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader moveit_task_constructor_gpd-srv:cloud_file-val is deprecated.  Use moveit_task_constructor_gpd-srv:cloud_file instead.")
  (cloud_file m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <PointCloud-request>) ostream)
  "Serializes a message object of type '<PointCloud-request>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'cloud_file))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'cloud_file))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <PointCloud-request>) istream)
  "Deserializes a message object of type '<PointCloud-request>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'cloud_file) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'cloud_file) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<PointCloud-request>)))
  "Returns string type for a service object of type '<PointCloud-request>"
  "moveit_task_constructor_gpd/PointCloudRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'PointCloud-request)))
  "Returns string type for a service object of type 'PointCloud-request"
  "moveit_task_constructor_gpd/PointCloudRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<PointCloud-request>)))
  "Returns md5sum for a message object of type '<PointCloud-request>"
  "94645eea953657df61f8fb2e51049aaa")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'PointCloud-request)))
  "Returns md5sum for a message object of type 'PointCloud-request"
  "94645eea953657df61f8fb2e51049aaa")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<PointCloud-request>)))
  "Returns full string definition for message of type '<PointCloud-request>"
  (cl:format cl:nil "# Request saving depth and rgb images~%# Input is file names to save them as~%string cloud_file~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'PointCloud-request)))
  "Returns full string definition for message of type 'PointCloud-request"
  (cl:format cl:nil "# Request saving depth and rgb images~%# Input is file names to save them as~%string cloud_file~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <PointCloud-request>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'cloud_file))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <PointCloud-request>))
  "Converts a ROS message object to a list"
  (cl:list 'PointCloud-request
    (cl:cons ':cloud_file (cloud_file msg))
))
;//! \htmlinclude PointCloud-response.msg.html

(cl:defclass <PointCloud-response> (roslisp-msg-protocol:ros-message)
  ()
)

(cl:defclass PointCloud-response (<PointCloud-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <PointCloud-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'PointCloud-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name moveit_task_constructor_gpd-srv:<PointCloud-response> is deprecated: use moveit_task_constructor_gpd-srv:PointCloud-response instead.")))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <PointCloud-response>) ostream)
  "Serializes a message object of type '<PointCloud-response>"
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <PointCloud-response>) istream)
  "Deserializes a message object of type '<PointCloud-response>"
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<PointCloud-response>)))
  "Returns string type for a service object of type '<PointCloud-response>"
  "moveit_task_constructor_gpd/PointCloudResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'PointCloud-response)))
  "Returns string type for a service object of type 'PointCloud-response"
  "moveit_task_constructor_gpd/PointCloudResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<PointCloud-response>)))
  "Returns md5sum for a message object of type '<PointCloud-response>"
  "94645eea953657df61f8fb2e51049aaa")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'PointCloud-response)))
  "Returns md5sum for a message object of type 'PointCloud-response"
  "94645eea953657df61f8fb2e51049aaa")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<PointCloud-response>)))
  "Returns full string definition for message of type '<PointCloud-response>"
  (cl:format cl:nil "~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'PointCloud-response)))
  "Returns full string definition for message of type 'PointCloud-response"
  (cl:format cl:nil "~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <PointCloud-response>))
  (cl:+ 0
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <PointCloud-response>))
  "Converts a ROS message object to a list"
  (cl:list 'PointCloud-response
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'PointCloud)))
  'PointCloud-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'PointCloud)))
  'PointCloud-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'PointCloud)))
  "Returns string type for a service object of type '<PointCloud>"
  "moveit_task_constructor_gpd/PointCloud")