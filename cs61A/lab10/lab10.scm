(define (over-or-under num1 num2) 
    (cond
        ((< num1 num2) -1)
        ((= num1 num2) 0)
        ((> num1 num2) 1)
    )
)

(define (make-adder num) 
    (lambda (inc) (+ num inc))
)

(define (composed f g) 
    (lambda (x) (f (g x)))
)

; ((1) 2 (3 4) 5)
(define lst
    (list '(1) 2 '(3 4) 5)
)

(define (duplicate lst) 'YOUR-CODE-HERE)
