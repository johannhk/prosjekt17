
(cl:in-package :asdf)

(defsystem "estimate_interest-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "DirectionStatus" :depends-on ("_package_DirectionStatus"))
    (:file "_package_DirectionStatus" :depends-on ("_package"))
    (:file "PersonInfo" :depends-on ("_package_PersonInfo"))
    (:file "_package_PersonInfo" :depends-on ("_package"))
    (:file "PersonsArray" :depends-on ("_package_PersonsArray"))
    (:file "_package_PersonsArray" :depends-on ("_package"))
  ))