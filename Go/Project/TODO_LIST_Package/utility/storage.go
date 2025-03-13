package utility

import (
	"encoding/json"
	"fmt"
	"os"
)

type Storage[T any] struct {
	FileName string
}

func NewStorage[T any](filename string) *Storage[T] {
	return &Storage[T]{FileName: filename}
}

func (s *Storage[T]) Save(data T) error {
	fileData, err := json.MarshalIndent(data, "", "   ")
	if err != nil {
		return err
	}
	return os.WriteFile(s.FileName, fileData, 0644)
}

// func (s *Storage[T]) Load(data *T) error {
func (s *Storage[T]) Load(data *T) error {
	fileData, err := os.ReadFile(s.FileName)
	if err != nil {
		fmt.Println("Reading error")
		return err
	}

	return json.Unmarshal(fileData, data)
}
