package main

import (
	"fmt"
	"sort"
	"strings"
)

func sortbyKeys(mymap map[string]int) {
	//create slice
	slice := make([]string, 0, len(mymap))

	for k := range mymap {
		slice = append(slice, k)
	}
	sort.Strings(slice)

	//print slice
	for _, k := range slice {
		fmt.Println(k, ":", mymap[k])
	}

}

func sortbyValue(m map[string]int) {

	//create slice
	slice := make([]int, 0, len(m))

	for _, v := range m {
		slice = append(slice, v)
	}
	sort.Ints(slice)

	type newSort struct {
		key   string
		value int
	}

	NS := []newSort{}
	//var NS []newSort

	for k, v := range m {
		temp := newSort{key: k, value: v}
		NS = append(NS, temp)
		//NS = append(NS, newSort{k, v})
	}

	//sort struct
	sort.Slice(NS, func(i int, j int) bool {
		return NS[i].value < NS[j].value
	})

	//print slice
	for _, v := range NS {
		fmt.Println(v.value, ":", v.key)
	}

}

func sortbyKeyCase(m map[string]int) {
	//create slice
	slice := make([]string, 0, len(m))

	for k := range m {
		slice = append(slice, k)
	}
	//sort.Strings(slice)
	//sort by case
	sort.Slice(slice, func(i, j int) bool {
		return strings.ToLower(slice[i]) < strings.ToLower(slice[j])
	})

	//print slice
	for _, k := range slice {
		fmt.Println(k, ":", m[k])
	}
}

func main() {
	mymap := map[string]int{"Banana": 2, "Pineaple": 3, "apple": 4, "Papaya": 5}

	/*fmt.Println("Print Map")
	for key, value := range mymap {
		fmt.Println("key:", key, " value:", value)
	}*/
	//sortbyKeys(mymap)
	fmt.Println("sort by value ")
	sortbyValue(mymap)
	// fmt.Println("sort by case ")
	// sortbyKeyCase(mymap)
}
