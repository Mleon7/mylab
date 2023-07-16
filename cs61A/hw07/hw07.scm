; chatgpt
(define (cddr s) (cdr (cdr s)))

(define (cadr s) (car (cdr s)))

(define (caddr s) (car (cdr (cdr s))))

; (define (ascending? asc-lst) 'YOUR-CODE-HERE)
(define (ascending? asc-lst)
  (cond
    ((null? asc-lst) #t) ; Empty list is considered ascending
    ((null? (cdr asc-lst)) #t) ; Single-element list is considered ascending
    ((<= (car asc-lst) (cadr asc-lst)) ; Compare the first two elements
     (ascending? (cdr asc-lst))) ; Recursively check the rest of the list
    (else #f))) ; If any pair of elements is not ascending, return False

(define (square n) (* n n))

; (define (pow base exp) 'YOUR-CODE-HERE)
(define (square n) (* n n))

(define (pow base exp)
  (cond ((= exp 0) 1)
        ((= exp 1) base)
        ((even? exp) (square (pow base (/ exp 2))))
        (else (* base (pow base (- exp 1))))))
