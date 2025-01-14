
(cl:in-package :asdf)

(defsystem "control_ur5-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :std_msgs-msg
)
  :components ((:file "_package")
    (:file "FilterScene" :depends-on ("_package_FilterScene"))
    (:file "_package_FilterScene" :depends-on ("_package"))
  ))