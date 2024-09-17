package main

import (
	"fmt"
	"runtime"
)

func main() {
	fmt.Println("main fucntion")
}

func Test() {

	pc, _, _, ok := runtime.Caller(1)
	details := runtime.FuncForPC(pc)
	if ok && details != nil {
		fmt.Printf("called from %s\n", details.Name())
	}
}
