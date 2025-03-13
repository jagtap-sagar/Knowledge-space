package main

import (
	"flag"
	"fmt"
	"strconv"
	"strings"
)

type CmdFlags struct {
	Add    string
	Edit   string
	Del    int
	Toggle int
	List   bool
}

func NewCmdFlag() *CmdFlags {
	//create struct object
	cf := CmdFlags{}

	flag.StringVar(&cf.Add, "Add", "", "Add to TODO list")
	flag.StringVar(&cf.Edit, "Edit", "", "Edit to TODO list")
	flag.IntVar(&cf.Del, "Del", -1, "Delete to TODO list")
	flag.IntVar(&cf.Toggle, "Toggle", -1, "Toggle to TODO list")
	flag.BoolVar(&cf.List, "List", false, "List to TODO list")

	//Parse the flag
	flag.Parse()

	return &cf
}

func (cf *CmdFlags) Execute(todos *TODOS) error {
	//todos slice(struct slice) is used to called function
	switch {
	case cf.Add != "":
		todos.add(cf.Add)

	case cf.Edit != "":
		parse := strings.SplitN(cf.Edit, ":", 2)
		if len(parse) < 2 {
			fmt.Println("Invalid argument for Edit")
			return nil
		}
		index, err := strconv.Atoi(parse[0])
		if err != nil {
			fmt.Println("Invalid index for Edit ")
			return nil
		}
		todos.edit(index, parse[1])

	case cf.Del != -1:
		todos.delete(cf.Del)

	case cf.Toggle != -1:
		todos.toggle(cf.Toggle)

	case cf.List:
		todos.print()

	default:
		fmt.Println("Invalid command ")
	}
	return nil
}
