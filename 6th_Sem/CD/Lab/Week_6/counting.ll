@.targetstr = constant [22 x i8] c"counting c's is cool!\00"
@.formatstr = constant [22 x i8] c"Number of c's is: %d\0A\00"

define dso_local i32 @main() {
    %targetptr = getelementptr [22 x i8], [22 x i8]* @.targetstr, i32 0, i32 0
    %1 = call i32 @countc(i8* %targetptr, i32 22)
    %formatptr = getelementptr [22 x i8], [22 x i8]* @.formatstr, i64 0, i64 0
    %2 = call i32 (i8*, ...) @printf(i8* %formatptr, i32 %1)
    ret i32 0
}

define dso_local i32 @countc(i8* %string, i32 %string_length) {
    %c_count = alloca i32
    %index = alloca i32
    store i32 0, i32* %c_count
    store i32 0, i32* %index
    br label %1

    1:
        %idx_1 = load i32, i32* %index
        %cmp_1 = icmp slt i32 %idx_1, %string_length
        br i1 %cmp_1, label %2, label %5
    
    2:
        %idx_2 = load i32, i32* %index
        %charptr = getelementptr i8, i8* %string, i32 %idx_2
        %char = load i8, i8* %charptr
        %cmp_2 = icmp eq i8 %char, 99
        br i1 %cmp_2, label %3, label %4
    
    3:
        %cnt = load i32, i32* %c_count
        %cnt_inc = add i32 %cnt, 1
        store i32 %cnt_inc, i32* %c_count
        br label %4
    
    4:
        %idx_3 = load i32, i32* %index
        %idx_3_inc = add i32 %idx_3, 1
        store i32 %idx_3_inc, i32* %index
        br label %1
    
    5:
        %retval = load i32, i32* %c_count
        ret i32 %retval
}

declare i32 @printf(i8*, ...)
