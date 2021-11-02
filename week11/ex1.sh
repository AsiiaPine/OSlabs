dd if=/dev/zero of=lofs.img bs=50MB count=1
sudo losetup -fP lofs.img
mkfs.ext4 lofs.img 
sudo mkdir /lofsdisk
sudo mount -o loop /dev/loop0 /lofsdisk

