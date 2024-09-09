// RUN: llvm-tblgen %s | FileCheck %s

class SumTillN<int n> {
    int v = !add(n, 0);
    int ret = !if(!gt(v, 0), !add(v, A<!sub(n, 1)>.ret), v);
}

// CHECK: def SumTill4
// CHECK-NEXT:  int v = 4;
// CHECK-NEXT:  int ret = 10;
def SumTill4 : SumTillN<4>;
