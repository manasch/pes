@.nameage = constant [20 x i8] c"Manas Chebrolu\0920Y\0A\00"

define dso_local i32 @main() {
    %nameage = getelementptr [20 x i8], [20 x i8]* @.nameage, i64 0, i64 0
    %1 = call i32 (i8*, ...) @printf(i8* %nameage)
    ret i32 0
}

declare i32 @printf(i8*, ...)
