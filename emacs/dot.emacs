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

; python autocomplete in emacs
(add-to-list 'load-path "~/.emacs.d")
(require 'auto-complete)
(global-auto-complete-mode t)

(require 'auto-complete-config)
(ac-ropemacs-initialize)
(global-auto-complete-mode t)
(define-key ac-complete-mode-map "\t" 'ac-expand)
(define-key ac-complete-mode-map "\r" 'ac-complete)
(define-key ac-complete-mode-map "\M-n" 'ac-next)
(define-key ac-complete-mode-map "\M-p" 'ac-previous)
(setq ac-auto-start 3)
(setq ac-dwim t)
(set-default 'ac-sources '(ac-source-abbrev ac-source-words-in-buffer))
(setq ac-modes
      (append ac-modes
	      '(eshell-mode
		)))

(set-face-background 'ac-menu-face "lightgray")
(set-face-underline 'ac-menu-face "darkgray")
(set-face-background 'ac-selection-face "steelblue")
