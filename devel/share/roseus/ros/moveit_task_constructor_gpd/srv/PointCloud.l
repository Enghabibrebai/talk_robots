;; Auto-generated. Do not edit!


(when (boundp 'moveit_task_constructor_gpd::PointCloud)
  (if (not (find-package "MOVEIT_TASK_CONSTRUCTOR_GPD"))
    (make-package "MOVEIT_TASK_CONSTRUCTOR_GPD"))
  (shadow 'PointCloud (find-package "MOVEIT_TASK_CONSTRUCTOR_GPD")))
(unless (find-package "MOVEIT_TASK_CONSTRUCTOR_GPD::POINTCLOUD")
  (make-package "MOVEIT_TASK_CONSTRUCTOR_GPD::POINTCLOUD"))
(unless (find-package "MOVEIT_TASK_CONSTRUCTOR_GPD::POINTCLOUDREQUEST")
  (make-package "MOVEIT_TASK_CONSTRUCTOR_GPD::POINTCLOUDREQUEST"))
(unless (find-package "MOVEIT_TASK_CONSTRUCTOR_GPD::POINTCLOUDRESPONSE")
  (make-package "MOVEIT_TASK_CONSTRUCTOR_GPD::POINTCLOUDRESPONSE"))

(in-package "ROS")





(defclass moveit_task_constructor_gpd::PointCloudRequest
  :super ros::object
  :slots (_cloud_file ))

(defmethod moveit_task_constructor_gpd::PointCloudRequest
  (:init
   (&key
    ((:cloud_file __cloud_file) "")
    )
   (send-super :init)
   (setq _cloud_file (string __cloud_file))
   self)
  (:cloud_file
   (&optional __cloud_file)
   (if __cloud_file (setq _cloud_file __cloud_file)) _cloud_file)
  (:serialization-length
   ()
   (+
    ;; string _cloud_file
    4 (length _cloud_file)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _cloud_file
       (write-long (length _cloud_file) s) (princ _cloud_file s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _cloud_file
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _cloud_file (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(defclass moveit_task_constructor_gpd::PointCloudResponse
  :super ros::object
  :slots ())

(defmethod moveit_task_constructor_gpd::PointCloudResponse
  (:init
   (&key
    )
   (send-super :init)
   self)
  (:serialization-length
   ()
   (+
    0
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;;
   self)
  )

(defclass moveit_task_constructor_gpd::PointCloud
  :super ros::object
  :slots ())

(setf (get moveit_task_constructor_gpd::PointCloud :md5sum-) "94645eea953657df61f8fb2e51049aaa")
(setf (get moveit_task_constructor_gpd::PointCloud :datatype-) "moveit_task_constructor_gpd/PointCloud")
(setf (get moveit_task_constructor_gpd::PointCloud :request) moveit_task_constructor_gpd::PointCloudRequest)
(setf (get moveit_task_constructor_gpd::PointCloud :response) moveit_task_constructor_gpd::PointCloudResponse)

(defmethod moveit_task_constructor_gpd::PointCloudRequest
  (:response () (instance moveit_task_constructor_gpd::PointCloudResponse :init)))

(setf (get moveit_task_constructor_gpd::PointCloudRequest :md5sum-) "94645eea953657df61f8fb2e51049aaa")
(setf (get moveit_task_constructor_gpd::PointCloudRequest :datatype-) "moveit_task_constructor_gpd/PointCloudRequest")
(setf (get moveit_task_constructor_gpd::PointCloudRequest :definition-)
      "# Request saving depth and rgb images
# Input is file names to save them as
string cloud_file
---

")

(setf (get moveit_task_constructor_gpd::PointCloudResponse :md5sum-) "94645eea953657df61f8fb2e51049aaa")
(setf (get moveit_task_constructor_gpd::PointCloudResponse :datatype-) "moveit_task_constructor_gpd/PointCloudResponse")
(setf (get moveit_task_constructor_gpd::PointCloudResponse :definition-)
      "# Request saving depth and rgb images
# Input is file names to save them as
string cloud_file
---

")



(provide :moveit_task_constructor_gpd/PointCloud "94645eea953657df61f8fb2e51049aaa")


