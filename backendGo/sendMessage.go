package main

import (
	"bufio"
	"flag"
	"fmt"
	"net"
	"os"
)

func main() {
	// this shoudld be IP of FS-SCENERY which can be checked in SILAB admin
	addr := flag.String("addr", "10.152.238.2:4200", "Address to connect to")
	// addr := flag.String("addr", "localhost:4200", "Address to connect to")
	// msg := flag.String("msg", "start\n", "Message to send")
	msg := flag.String("msg", "trf", "Message to send")

	flag.Parse()

	fmt.Printf("connecting to %q...\n", *addr)

	conn, err := net.Dial("tcp", *addr)
	if err != nil {
		fmt.Fprintf(os.Stderr, "failed to connect to server: %v\n", err)
		return
	}

	defer conn.Close()

	fmt.Println("connected")

	fmt.Printf("-- sending --\n%s\n-- sending --\n", *msg)

	writer := bufio.NewWriter(conn)

	_, err = writer.WriteString(*msg + "\n")
	if err != nil {
		fmt.Fprintf(os.Stderr, "failed to write message: %v\n", err)
		return
	}

	err = writer.Flush()
	if err != nil {
		fmt.Fprintf(os.Stderr, "failed to flush buffer: %v\n", err)
		return
	}

	fmt.Println("message sent, waiting for result...")

	reader := bufio.NewReader(conn)
	res, err := reader.ReadString('')
	if err != nil {
		fmt.Fprintf(os.Stderr, "failed to read response: %v\n", err)
		return
	}

	fmt.Printf("-- response --\n%s\n-- response --\n", res)
}
