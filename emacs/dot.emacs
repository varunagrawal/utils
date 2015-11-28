(custom-set-variables
 ;; custom-set-variables was added by Custom.
 ;; If you edit it by hand, you could mess it up, so be careful.
 ;; Your init file should contain only one such instance.
 ;; If there is more than one, they won't work right.
 '(custom-enabled-themes (quote (wombat))))
(custom-set-faces
 ;; custom-set-faces was added by Custom.
 ;; If you edit it by hand, you could mess it up, so be careful.
 ;; Your init file should contain only one such instance.
 ;; If there is more than one, they won't work right.
 )

;; Put autosave files (ie #foo#) and backup files (ie foo~) in ~/.emacs.d/.
;(custom-set-variables
; '(auto-save-file-name-transforms '((".*" "~/.emacs.d/autosaves/\\1" t)))
; '(backup-directory-alist '((".*" . "~/.emacs.d/backups/"))))

;; create the autosave dir if necessary, since emacs won't.
;(make-directory "~/.emacs.d/autosaves/" t)
;(make-directory "~/.emacs.d/backups/" t)

(setq backup-directory-alist
      `((".*" . ,temporary-file-directory)))
(setq auto-save-file-name-transforms
      `((".*" ,temporary-file-directory t)))

(message "Deleting old backup files...")
(let ((week (* 60 60 24 7))
      (current (float-time (current-time))))
  (dolist (file (directory-files temporary-file-directory t))
    (when (and (backup-file-name-p file)
	       (> (- current (float-time (nth 5 (file-attributes file))))
		  week))
      (message "%s" file)
            (delete-file file))))

; set the c indent style to linux rather than the default GNU style
(setq c-default-style "linux"
      c-basic-offset 4)

(setq x-select-enable-clipboard t)

