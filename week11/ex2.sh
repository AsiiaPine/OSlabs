sudo touch /lofsdisk/file1
sudo echo 'Anastasiia' > /lofsdisk/file1
sudo touch /lofsdisk/file2
sudo echo 'Baranova' > /lofsdisk/file2

gcc ex2.c -o ex2.out
sudo cp ex2.out /lofsdisk/ex2.out

sudo mkdir -p /lofsdisk/usr/lib
sudo mkdir -p /lofsdisk/usr/lib64
sudo mkdir -p /lofsdisk/lib
sudo mkdir -p /lofsdisk/lib64

sudo cp /bin/bash /lofsdisk/bin/
sudo cp /bin/cat /lofsdisk/bin/
sudo cp /bin/echo /lofsdisk/bin/
sudo cp /bin/ls /lofsdisk/bin/

sudo cp /usr/lib/libreadline.so.8 /lofsdisk/usr/lib
sudo cp /usr/lib/libl.so.2 /lofsdisk/usr/lib
sudo cp /usr/lib/libdl.so.2 /lofsdisk/usr/lib
sudo cp /usr/lib/libc.so.6 /lofsdisk/usr/lib
sudo cp /usr/lib/libncursesw.so.6 /lofsdisk/usr/lib
sudo cp /usr/lib64/ld-linux-x86-64.so.2 /lofsdisk/usr/lib64
sudo cp /lofsdisk/usr/lib/* /lofsdisk/lib/
sudo cp /lofsdisk/usr/lib64/* /lofsdisk/lib64/

sudo chroot /lofsdisk /ex2.out > ex2.txt
echo 'Local FS output:' >> ex2.txt
./ex2.out >> ex2.txt
