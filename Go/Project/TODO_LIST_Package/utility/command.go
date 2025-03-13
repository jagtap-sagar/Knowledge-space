package utility

import (
	"flag"
	"fmt"

	//cmd "gopackage/utility"
	"strconv"
	"strings"
)

type CmdFlags struct {
	Add  string
	Edit string
	Del  int
	Done int
	Undo int
	List bool
}

func NewCmdFlag() *CmdFlags {
	//create struct object
	cf := CmdFlags{}

	//StringVar allows you to bind a flag directly to an existing variable in your program.
	flag.StringVar(&cf.Add, "Add", "", "Add to TODO list")
	flag.StringVar(&cf.Edit, "Edit", "", "Edit to TODO list")
	flag.IntVar(&cf.Del, "Del", -1, "Delete to TODO list")
	flag.IntVar(&cf.Done, "Done", -1, "Toggle to TODO list")
	flag.IntVar(&cf.Undo, "Undo", -1, "Toggle to TODO list")
	flag.BoolVar(&cf.List, "List", false, "List to TODO list")

	//flag.Parse(): Parses the command-line arguments.
	flag.Parse()

	return &cf
}

func (cf *CmdFlags) Execute(todos *TODOS) error {
	//todos slice(struct slice) is used to called function
	switch {
	case cf.Add != "":
		todos.AddRow(cf.Add)

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
		todos.EditRow(index, parse[1])

	case cf.Del != -1:
		todos.Delete(cf.Del)

	case cf.Done != -1:
		todos.ToggleRow(cf.Done)

	case cf.Undo != -1:
		todos.ToggleRow(cf.Undo)

	case cf.List:
		todos.Print()

	default:
		fmt.Println("Invalid command ")
	}
	return nil
}
