package main

import (
	"fmt"
)

type Stack struct {
	row     []int
	column  []int
	top     int
	maxSize int
}

func newStack() *Stack {
	p := new(Stack)
	p.maxSize = 100
	p.top = -1
	p.row = make([]int, p.maxSize)
	p.column = make([]int, p.maxSize)
	return p
}

func (stack Stack) isFull() bool {
	if stack.top == stack.maxSize-1 {
		return true
	}
	return false
}

func (stack Stack) isEmpty() bool {
	if stack.top == -1 {
		return true
	}
	return false
}

func (stack *Stack) pop() (x, y int, ok bool) {
	if !stack.isEmpty() {
		x = stack.row[stack.top]
		y = stack.column[stack.top]
		stack.top--
		ok = true
	} else {
		ok = false
		x = -1
		y = -1
	}
	return
}

func (stack *Stack) push(x, y int) bool {
	if ok := stack.isFull(); !ok {
		stack.top += 1
		stack.row[stack.top] = x
		stack.column[stack.top] = y
		return true
	}
	return false
}

func (stack Stack) show() (x, y int, ok bool) {
	if !stack.isEmpty() {
		x = stack.row[stack.top]
		y = stack.column[stack.top]
		ok = true
	} else {
		ok = false
		x = -1
		y = -1
	}
	return
}

// Find location start point of the maze 
func findStartPoint(list [][]int, start int) (x, y int) {
	for i := 0; i < len(list); i++ {
		if list[i][0] == start {
			x = i
			y = 0
			break
		}
	}
	return
}

var maze = [][]int{
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 0
	{2, 1, 1, 0, 1, 1, 1, 1, 1, 0},	// 1
	{0, 1, 0, 0, 1, 0, 0, 0, 1, 0},	// 2	
	{0, 1, 1, 1, 1, 0, 1, 0, 1, 0},	// 3
	{0, 0, 0, 0, 1, 0, 1, 1, 1, 0},	// 4
	{0, 1, 1, 1, 1, 1, 1, 0, 1, 3}, // 5
	{0, 1, 0, 0, 0, 0, 0, 0, 1, 0},	// 6
	{0, 1, 1, 1, 1, 1, 0, 1, 1, 0},	// 7
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	// 8
}

func run(pr, pc int, stack *Stack, end int) bool {
	if maze[pr][pc] == end { // if for the end of the function
		return true
	}

	maze[pr][pc] = 5 // flagging the way traveled

	if pr+1 < len(maze) && (maze[pr+1][pc] == 1 || maze[pr+1][pc] == end) { // Turn down
		stack.push(pr+1, pc)
		if run(pr+1, pc, stack, end) {
			return true
		}
		stack.pop()
	}
	if pr-1 >= 0 && (maze[pr-1][pc] == 1 || maze[pr-1][pc] == end) { // Turn up
		stack.push(pr-1, pc)
		if run(pr-1, pc, stack, end) {
			return true
		}
		stack.pop()
	}
	if pc+1 < len(maze[0]) && (maze[pr][pc+1] == 1 || maze[pr][pc+1] == end) { // Turn right
		stack.push(pr, pc+1)
		if run(pr, pc+1, stack, end) {
			return true
		}
		stack.pop()
	}
	if pc-1 >= 0 && (maze[pr][pc-1] == 1 || maze[pr][pc-1] == end) { // Turn left
		stack.push(pr, pc-1)
		if run(pr, pc-1, stack, end) {
			return true
		}
		stack.pop()
	}
	return false
}

func main() {
	sr, sc := findStartPoint(maze, 2) // Start row and Start column
	stack := newStack() // make stack with constructor

	pr, pc := sr, sc // Pointer row and Pointer column
	stack.push(pr, pc)
	
	// Copy maze into another slice => copyMaze
	copyMaze := make([][]int, len(maze))
	for i := range maze {
		copyMaze[i] = make([]int, len(maze[i]))
		copy(copyMaze[i], maze[i])
	}

	ok := run(pr, pc, stack, 3)

	if ok {
		fmt.Println("Way founded!")

		for {
			x, y, o := stack.pop()
			if !o {
				break
			}
			fmt.Printf("(%d,%d) - ", x, y) // print location of true way
			copyMaze[x][y] = 5 // flagging true way
		}
		fmt.Print("\n")
		for i := 0; i < len(copyMaze); i++ {
			for j := 0; j < len(copyMaze[0]); j++ {
				if copyMaze[i][j] == 5 {
					fmt.Print("*  ")
				} else {
					fmt.Printf("%d  ", copyMaze[i][j])
				}
			}
			fmt.Print("\n")
		}
	}else {
		fmt.Println("Way not Founded!")
	}

}
