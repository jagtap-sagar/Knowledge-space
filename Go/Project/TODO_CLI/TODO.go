package main

import (
	"errors"
	"fmt"
	"os"
	"strconv"
	"time"

	"github.com/aquasecurity/table"
	//"golang.org/x/tools/go/analysis/passes/nilfunc"
)

//TODO Create package for this

//define structure  for TODO list

var counter int

type TODOLIST struct {
	Id          int
	Title       string
	Completed   bool
	CreatedAt   time.Time
	CompletedAt *time.Time
}

// define slice of struct
type TODOS []TODOLIST

func (todos *TODOS) add(name string) {
	//todos.Id = counter++ //Find why increament operator not work
	//The expression counter++ first returns the current value of counter and then increments it.
	temp := TODOLIST{}
	counter++
	temp.Id = counter
	temp.Title = name
	temp.Completed = false
	temp.CreatedAt = time.Now()
	temp.CompletedAt = nil

	*todos = append(*todos, temp)

}

func (todos *TODOS) validate(index int) error {

	if index < 0 || index > len(*todos) {
		err := errors.New("Invalid Index")
		fmt.Println("Error", err)
		return err
	}
	// index is valid,so send nil
	return nil
}

func (todos *TODOS) delete(index int) error {

	//t := *todos
	if err := todos.validate(index); err != nil {
		return nil
	}
	*todos = append((*todos)[:index], (*todos)[index+1:]...)
	//*todos = append(t[:index], t[index+1:]...)
	return nil
}

// Toogle method is used to if comleted task then make it not completed ,
//
//	if it is NOT completed then make it completed like flip.
//
// if True then false , if false then True.
func (todos *TODOS) toggle(index int) error {
	if err := todos.validate(index); err != nil {
		return err
	}

	isCompleted := (*todos)[index].Completed
	if !isCompleted {
		temp := time.Now()
		(*todos)[index].CompletedAt = &temp //why can't we assign time directly like &(time.Now())
	}

	(*todos)[index].Completed = !isCompleted

	return nil
}

func (todos *TODOS) edit(index int, title string) error {

	if err := todos.validate(index); err != nil {
		return err
	}

	(*todos)[index].Title = title
	return nil
}

func (todos *TODOS) print() {
	table := table.New(os.Stdout)
	table.SetRowLines(false)
	table.SetHeaders("#", "Title", "Completed", "CreatedAt", "CompletedAt")

	for index, t := range *todos {
		completed := "❌"
		completedAt := ""

		if t.Completed {
			completed = "✅"
			if t.CompletedAt != nil {
				completedAt = t.CompletedAt.Format(time.RFC1123)
			}
		}
		//table.AddRow(strconv.Itoa(index), t.Title, completed, " ", completedAt)
		formattedTime := t.CreatedAt // currentTime.Format(time.RFC1123)
		temp := formattedTime.Format(time.RFC1123)
		//time.Parse(time.RFC3339, t.CompletedAt.Format(time.RFC1123))
		table.AddRow(strconv.Itoa(index), t.Title, completed, (temp), completedAt)
	}

	table.Render()
}
