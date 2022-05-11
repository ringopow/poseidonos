package grpcmgr

import (
	"cli/cmd/globals"
	"context"
	"pnconnector/src/log"
	"time"

	pb "cli/api"

	"google.golang.org/grpc"
)

func SendReqAndReceiveRes(req *pb.SystemInfoRequest) (*pb.SystemInfoResponse, error) {
	conn, err := grpc.Dial(globals.GrpcServerAddress, grpc.WithInsecure(), grpc.WithBlock())
	if err != nil {
		log.Error("cannot send a request to cli server: not connected")
		return nil, err
	}
	defer conn.Close()

	c := pb.NewPosCliClient(conn)
	ctx, cancel := context.WithTimeout(context.Background(), time.Second)
	defer cancel()

	res, err := c.SystemInfo(ctx, req)

	return res, err
}