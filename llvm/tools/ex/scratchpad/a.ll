
define i64 @rett(i32 %a, i32 %b) {
entry:
    %aext = zext i32 %a to i64
    %bext = zext i32 %b to i64
    %ret = add i64 %aext, %bext
    ret i64 %ret
}

; function
define i4 @main(i32 %argc, i8** %argv) {
entry:
    ; %a = add i32 5, %argc
    ; branch if a is 10
    %bc = icmp eq i32 %argc, 10
    br i1 %bc, label %if.then, label %if.else
if.then:
    %a = add nsw i32 4, %argc
    br label %end
if.else:
    %b = add nsw i32 5, %argc
    br label %end
end:
    %c = phi i32 [ %a, %if.then ], [ %b, %if.else ]
    %d = add i32 %c, 1
    ; split the value into [32 x i1]
    %ret.val = alloca [32 x i1], align 4
    %ret = bitcast [32 x i1]* %ret.val to i8*
    br label %loop
loop:
    %i1 = phi i32 [ 0, %end ], [ %i2, %loop ]
    %v = getelementptr inbounds [32 x i1], [32 x i1]* %ret.val, i32 0, i32 %i1
    store i1 0, i1* %v, align 1
    %i2 = add i32 %i1, 1
    %cmp = icmp eq i32 %i1, 32
    br i1 %cmp, label %end.loop, label %loop
end.loop:
    ; return the value in %ret
    %vret = load [32 x i1], [32 x i1]* %ret.val, align 4
    %bitcasted = trunc i32 %i1 to i4
    ret i4 %bitcasted
    ; ret [32 x i1] %vret
}
