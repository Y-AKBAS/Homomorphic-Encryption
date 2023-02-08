
$plugin = "C:/vcpkg/packages/grpc_x64-windows/tools/grpc/grpc_cpp_plugin.exe"
$outfileDir = "C:/Users/monster/source/repos/ThesisEncryption/out/build/x64-debug"
$fileInfo = "communication.proto"

cd $PSScriptRoot
protoc -I="." --grpc_out=$outfileDir --plugin=protoc-gen-grpc=$plugin $fileInfo
protoc -I="." --cpp_out=$outfileDir $fileInfo