package main

import (
	"fmt"
)

func main() {
	fmt.Println("Main list")

	todos := TODOS{}

	storage := NewStorage[TODOS]("todos.json")
	storage.Load(&todos) //here u forgot to pass address & in fun defination Not take pointer
	cmdflag := NewCmdFlag()
	cmdflag.Execute(&todos)
	//todos.print()
	storage.Save(todos)

	/*
		todos.add("Buy Milk")
		todos.add("Buy Bread")
		storage := NewStorage[TODOS]("todos.json")
		//storage.Load(&todos)
		storage.Load(&todos)
		defer storage.Save(todos)
		time.Sleep(2 * time.Second)
		//fmt.Printf("%+v\n", todos)
		//todos.delete(0)
		todos.toggle(0)
		todos.print()
	*/
}
