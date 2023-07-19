; (define-macro (when condition exprs)
;   'YOUR-CODE-HERE)

; (define-macro (switch expr cases)
;   (cons _________
;         (map (_________ (_________)
;                         (cons _________ (cdr case)))
;              cases)))

; https://github.com/winnwy/CS61A-Fall22/blob/main/cs61a/hw/hw09/hw09.scm
(define-macro (when condition exprs)
  `(if ,condition ,(cons 'begin exprs) 'okay)
  )

(define-macro (switch expr cases)
  (cons `cond
        (map (lambda (case)
                        (cons `(equal? ,expr ',(car case)) (cdr case)))
             cases)))