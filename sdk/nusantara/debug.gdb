# Skip file header standar
skip -gfi /usr/include/c++/*
skip -gfi /usr/include/c++/*/*
skip -gfi /usr/include/c++/*/*/*

# Break point main function
b main

# Mulai eksekusi program
run $HOME/development/Nusantara-Language/sdk/nusantara/examples/halo_dunia.nl

# Perulangan while untuk menjalankan step sampai program selesai
while !$_exitcode
  s
end
