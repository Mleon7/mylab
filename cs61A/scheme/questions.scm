(define (caar x) (car (car x)))
(define (cadr x) (car (cdr x)))
(define (cdar x) (cdr (car x)))
(define (cddr x) (cdr (cdr x)))

;; Problem 15
;; Returns a list of two-element lists
; (define (enumerate s)
; chatgpt, 可能是不同scheme用的函数啥的不一样，生成了好几次才有这个
(define (enumerate lst)
  ; BEGIN PROBLEM 15
  (define (enumerate-helper lst index)
    (cond
      ((null? lst) '()) ; base case: empty list
      (else
       (cons (list index (car lst))
             (enumerate-helper (cdr lst) (+ index 1)))) ; recursive case
      )
    )
  (enumerate-helper lst 0) ; start the recursion with index 0
  )
  ; END PROBLEM 15

;; Problem 16

;; Merge two lists LIST1 and LIST2 according to ORDERED? and return
;; the merged lists.
; (define (merge ordered? list1 list2)
  ; BEGIN PROBLEM 16
; 果不其然，保持problem 15的上文，拿promblem 16的问题再提问chatgpt，直接就得到了正确答案
(define (merge ordered? lst1 lst2)
  (cond
    ((null? lst1) lst2) ; base case: lst1 is empty, return lst2
    ((null? lst2) lst1) ; base case: lst2 is empty, return lst1
    ((ordered? (car lst1) (car lst2)) ; compare the first elements
     (cons (car lst1) (merge ordered? (cdr lst1) lst2))) ; lst1 element is smaller
    (else
     (cons (car lst2) (merge ordered? lst1 (cdr lst2)))) ; lst2 element is smaller
    )
  )
  ; END PROBLEM 16

;; Optional Problem 2

;; Returns a function that checks if an expression is the special form FORM
(define (check-special form)
  (lambda (expr) (equal? form (car expr))))

(define lambda? (check-special 'lambda))
(define define? (check-special 'define))
(define quoted? (check-special 'quote))
(define let?    (check-special 'let))

;; Converts all let special forms in EXPR into equivalent forms using lambda
(define (let-to-lambda expr)
  (cond ((atom? expr)
         ; BEGIN OPTIONAL PROBLEM 2
         'replace-this-line
         ; END OPTIONAL PROBLEM 2
         )
        ((quoted? expr)
         ; BEGIN OPTIONAL PROBLEM 2
         'replace-this-line
         ; END OPTIONAL PROBLEM 2
         )
        ((or (lambda? expr)
             (define? expr))
         (let ((form   (car expr))
               (params (cadr expr))
               (body   (cddr expr)))
           ; BEGIN OPTIONAL PROBLEM 2
           'replace-this-line
           ; END OPTIONAL PROBLEM 2
           ))
        ((let? expr)
         (let ((values (cadr expr))
               (body   (cddr expr)))
           ; BEGIN OPTIONAL PROBLEM 2
           'replace-this-line
           ; END OPTIONAL PROBLEM 2
           ))
        (else
         ; BEGIN OPTIONAL PROBLEM 2
         'replace-this-line
         ; END OPTIONAL PROBLEM 2
         )))

; Some utility functions that you may find useful to implement for let-to-lambda

(define (zip pairs)
  'replace-this-line)
