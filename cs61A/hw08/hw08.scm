; 我自己的思路是，弄一个新的list，然后符合的就加进去，最后返回该list
; chatgpt
    ; 1. The base case of the recursion is when the list s is empty. In this case, we return an empty list '() because there are no elements left to filter.

    ; 2. If the list s is not empty, we check if the predicate pred is true for the first element of the list using (pred (car s)).

    ; 3. If the predicate is true for the first element, we cons (car s) with the result of recursively calling my-filter on the rest of the list (cdr s). This adds the first element to the filtered list.

    ; 4. If the predicate is false for the first element, we skip it and directly call my-filter on the rest of the list (cdr s).
(define (my-filter pred s)
  (if (null? s)
      '()
      (if (pred (car s))
          (cons (car s) (my-filter pred (cdr s)))
          (my-filter pred (cdr s)))))

; chatgpt
(define (interleave lst1 lst2) ; The function takes two lists lst1 and lst2 as input.
  (cond
    ((null? lst1) lst2)
    ((null? lst2) lst1)        ; It checks if either of the lists is empty. If lst1 is empty, it returns lst2 as the result. If lst2 is empty, it returns lst1 as the result.
    (else (cons (car lst1)     ; If both lists have at least one element, it interleaves the elements by taking the first element from lst1 ((car lst1)) and the first element from lst2 ((car lst2)) and cons them together using the cons function.
                (cons (car lst2)
                      (interleave (cdr lst1) (cdr lst2)))))))

; chatgpt
(define (accumulate joiner start n term)
    (if (= n 0)
      start
      (joiner (term n) (accumulate joiner start (- n 1) term))))

; chatgpt
; (define (no-repeats lst) 
;   (define (seen-before? x seen)
;     (cond ((null? seen) #f)
;           ((= x (car seen)) #t)
;           (else (seen-before? x (cdr seen)))))

;   (define (unique-elements lst seen)
;     (cond ((null? lst) '())
;           ((seen-before? (car lst) seen)
;            (unique-elements (cdr lst) seen))
;           (else (cons (car lst)
;                       (unique-elements (cdr lst) (cons (car lst) seen))))))

;   (unique-elements lst '()))

; chatgpt(another version)
(define (no-repeats lst)
  (if (null? lst)
      '()
      (cons (car lst)
            (no-repeats (my-filter (lambda (x) (not (= x (car lst)))) (cdr lst))))))

