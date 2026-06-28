package main

import (
	"bufio"
	"flag"
	"fmt"
	"net"
	"os"
)

func main() {
	// this should be IP of FS-SCENERY which can be checked in SILAB admin
	addr := flag.String("addr", "10.152.238.2:4200", "Address to connect to")
	// addr := flag.String("addr", "localhost:4200", "Address to connect to")

	// With no flag the tool reads the current ADAS state via "automation".
	// --on  turns the driving automation on  (server "start" command).
	// --off turns the driving automation off (server "stop" command).
	on := flag.Bool("on", false, "Turn the driving automation on")
	off := flag.Bool("off", false, "Turn the driving automation off")

	flag.Parse()

	if *on && *off {
		fmt.Fprintln(os.Stderr, "cannot use --on and --off together")
		return
	}

	msg := "automation"
	if *on {
		msg = "start"
	} else if *off {
		msg = "stop"
	}

	fmt.Printf("connecting to %q...\n", *addr)

	conn, err := net.Dial("tcp", *addr)
	if err != nil {
		fmt.Fprintf(os.Stderr, "failed to connect to server: %v\n", err)
		return
	}

	defer conn.Close()

	fmt.Println("connected")

	fmt.Printf("-- sending --\n%s\n-- sending --\n", msg)

	writer := bufio.NewWriter(conn)

	_, err = writer.WriteString(msg + "\n")
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

	// The server terminates each response with the ETX byte ().
	reader := bufio.NewReader(conn)
	res, err := reader.ReadString('')
	if err != nil {
		fmt.Fprintf(os.Stderr, "failed to read response: %v\n", err)
		return
	}

	fmt.Printf("-- response --\n%s\n-- response --\n", res)
}
