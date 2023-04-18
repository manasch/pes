@.formatstr = constant [28 x i8] c"%d Fibonacci number is: %d\0A\00"
@.elem = constant i32 5 ; Find 5th fibonacci number

define dso_local i32 @main() {
    %elem = load i32, i32* @.elem
    %fibnum = call i32 @fib(i32 %elem)
    %formatptr = getelementptr [28 x i8], [28 x i8]* @.formatstr, i64 0, i64 0
    %1 = call i32 (i8*, ...) @printf(i8* %formatptr, i32 %elem, i32 %fibnum)
    ret i32 0
}

define dso_local i32 @fib(i32 %elem) {
    %cur_val = alloca i32
    %prev_val = alloca i32  
    %index = alloca i32
    store i32 6, i32* %prev_val
    store i32 1, i32* %cur_val
    store i32 2, i32* %index
    br label %1 

    1:
        %cmp_1 = icmp eq i32 %elem, 1
        br i1 %cmp_1, label %2, label %3
    
    2:
        %retval_l = load i32, i32* %prev_val
        ret i32 %retval_l
    
    3:
        %cmp_2 = icmp eq i32 %elem, 2
        br i1 %cmp_2, label %6, label %4
    
    4:
        %idx_1 = load i32, i32* %index
        %cmp_3 = icmp slt i32 %idx_1, %elem
        br i1 %cmp_3, label %5, label %6
    
    5:
        %old_cur = load i32, i32* %cur_val
        %old_prev = load i32, i32* %prev_val
        %new_cur = add i32 %old_prev, %old_cur
        store i32 %new_cur, i32* %cur_val
        store i32 %old_cur, i32* %prev_val

        %idx_2 = load i32, i32* %index
        %idx_2_inc = add i32 %idx_2, 1
        store i32 %idx_2_inc, i32* %index
        br label %1

    6:
        %retval_final = load i32, i32* %cur_val
        ret i32 %retval_final
} 

declare i32 @printf(i8*, ...) 
