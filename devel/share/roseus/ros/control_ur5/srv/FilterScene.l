;; Auto-generated. Do not edit!


(when (boundp 'control_ur5::FilterScene)
  (if (not (find-package "CONTROL_UR5"))
    (make-package "CONTROL_UR5"))
  (shadow 'FilterScene (find-package "CONTROL_UR5")))
(unless (find-package "CONTROL_UR5::FILTERSCENE")
  (make-package "CONTROL_UR5::FILTERSCENE"))
(unless (find-package "CONTROL_UR5::FILTERSCENEREQUEST")
  (make-package "CONTROL_UR5::FILTERSCENEREQUEST"))
(unless (find-package "CONTROL_UR5::FILTERSCENERESPONSE")
  (make-package "CONTROL_UR5::FILTERSCENERESPONSE"))

(in-package "ROS")

(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass control_ur5::FilterSceneRequest
  :super ros::object
  :slots (_pointcloud_topic _image_topic ))

(defmethod control_ur5::FilterSceneRequest
  (:init
   (&key
    ((:pointcloud_topic __pointcloud_topic) (instance std_msgs::String :init))
    ((:image_topic __image_topic) (instance std_msgs::String :init))
    )
   (send-super :init)
   (setq _pointcloud_topic __pointcloud_topic)
   (setq _image_topic __image_topic)
   self)
  (:pointcloud_topic
   (&rest __pointcloud_topic)
   (if (keywordp (car __pointcloud_topic))
       (send* _pointcloud_topic __pointcloud_topic)
     (progn
       (if __pointcloud_topic (setq _pointcloud_topic (car __pointcloud_topic)))
       _pointcloud_topic)))
  (:image_topic
   (&rest __image_topic)
   (if (keywordp (car __image_topic))
       (send* _image_topic __image_topic)
     (progn
       (if __image_topic (setq _image_topic (car __image_topic)))
       _image_topic)))
  (:serialization-length
   ()
   (+
    ;; std_msgs/String _pointcloud_topic
    (send _pointcloud_topic :serialization-length)
    ;; std_msgs/String _image_topic
    (send _image_topic :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/String _pointcloud_topic
       (send _pointcloud_topic :serialize s)
     ;; std_msgs/String _image_topic
       (send _image_topic :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/String _pointcloud_topic
     (send _pointcloud_topic :deserialize buf ptr-) (incf ptr- (send _pointcloud_topic :serialization-length))
   ;; std_msgs/String _image_topic
     (send _image_topic :deserialize buf ptr-) (incf ptr- (send _image_topic :serialization-length))
   ;;
   self)
  )

(defclass control_ur5::FilterSceneResponse
  :super ros::object
  :slots (_finished ))

(defmethod control_ur5::FilterSceneResponse
  (:init
   (&key
    ((:finished __finished) (instance std_msgs::Empty :init))
    )
   (send-super :init)
   (setq _finished __finished)
   self)
  (:finished
   (&rest __finished)
   (if (keywordp (car __finished))
       (send* _finished __finished)
     (progn
       (if __finished (setq _finished (car __finished)))
       _finished)))
  (:serialization-length
   ()
   (+
    ;; std_msgs/Empty _finished
    (send _finished :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Empty _finished
       (send _finished :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Empty _finished
     (send _finished :deserialize buf ptr-) (incf ptr- (send _finished :serialization-length))
   ;;
   self)
  )

(defclass control_ur5::FilterScene
  :super ros::object
  :slots ())

(setf (get control_ur5::FilterScene :md5sum-) "ea94d240c31365a6cbd92625f469bbdc")
(setf (get control_ur5::FilterScene :datatype-) "control_ur5/FilterScene")
(setf (get control_ur5::FilterScene :request) control_ur5::FilterSceneRequest)
(setf (get control_ur5::FilterScene :response) control_ur5::FilterSceneResponse)

(defmethod control_ur5::FilterSceneRequest
  (:response () (instance control_ur5::FilterSceneResponse :init)))

(setf (get control_ur5::FilterSceneRequest :md5sum-) "ea94d240c31365a6cbd92625f469bbdc")
(setf (get control_ur5::FilterSceneRequest :datatype-) "control_ur5/FilterSceneRequest")
(setf (get control_ur5::FilterSceneRequest :definition-)
      "std_msgs/String pointcloud_topic
std_msgs/String image_topic

================================================================================
MSG: std_msgs/String
string data
---
std_msgs/Empty finished

================================================================================
MSG: std_msgs/Empty
")

(setf (get control_ur5::FilterSceneResponse :md5sum-) "ea94d240c31365a6cbd92625f469bbdc")
(setf (get control_ur5::FilterSceneResponse :datatype-) "control_ur5/FilterSceneResponse")
(setf (get control_ur5::FilterSceneResponse :definition-)
      "std_msgs/String pointcloud_topic
std_msgs/String image_topic

================================================================================
MSG: std_msgs/String
string data
---
std_msgs/Empty finished

================================================================================
MSG: std_msgs/Empty
")



(provide :control_ur5/FilterScene "ea94d240c31365a6cbd92625f469bbdc")


