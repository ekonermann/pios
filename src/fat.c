#include "fat.h"
#include "sd.h"
#include "serial.h"
#include "clibfuncs.h"
#include "rprintf.h"

struct boot_sector *bs;
char bootSector[512]; //allocate a global array to store the boot sector
char rootSector[512];
//char fat_table[8*SECTOR_SIZE];
struct root_directory_entry *fat;
unsigned int root_sector;

int fatInit() {
	char buffer[10];
	sd_readblock(0, bootSector, 1);
	int k = 0;
	while(bs->fs_type[k] != ' ' || k >= 8){
		esp_printf((void*)putc, "%c", bs->fs_type[k]);
		buffer[k] = bs->fs_type[k];
		k++;
		buffer[k] = 0;
	}
	if(bs->boot_signature = 0xaa55){
		esp_printf((void*)putc, "Boot signature verified \n");
	}
	if(strcmp(buffer, "FAT16")){
		esp_printf((void*)putc, "FAT16 \n \n");
	}


	esp_printf((void*)putc,"Bytes per sector: %d \n" ,bs->bytes_per_sector);
	esp_printf((void*)putc,"Sectors per cluster: %d \n" ,bs->num_sectors_per_cluster);
	esp_printf((void*)putc,"Reserved sectors: %d \n" ,bs->num_reserved_sectors);
	esp_printf((void*)putc,"Fat table: %d \n" ,bs->num_fat_tables);
	esp_printf((void*)putc,"Root directory entries: %d \n" ,bs->num_root_dir_entries);
	//root sector calculation
	int root_value = ((bs->num_fat_tables * bs->num_sectors_per_fat) + bs->num_hidden_sectors + bs->num_reserved_sectors);
	esp_printf((void*)putc,"Root sector value: %d \n", root_value); 
}

fatOpen(struct file* file, char* filename){
	int t_sectors = bs-> num_root_dir_entries;  
	int t = 1;
	char buffer[10];
	int root_value = ((bs->num_fat_tables * bs->num_sectors_per_fat) + bs->num_reserved_sectors + bs->num_hidden_sectors);
	esp_printf(putc, "Boot sector: %x\n", bs);
	sd_readblock(root_value, rootSector, 1);
	fat = rootSector;
	while(t < t_sectors ){
		int j = 0;
		while(j < 8){
			esp_printf(putc, "%c", fat->file_name[j]);
			if(fat->file_name[j] != ' ')
				buffer[j] = fat->file_name[j];
			j++;
		}
		buffer[7] = 0;
		if(strcmp(buffer, filename) == 0){
			esp_printf(putc, "Buffer's equal");
			file->rde = *fat;
			file->start_cluster = fat->cluster;
			return;
		}
		esp_printf(putc, "\n%s\n", buffer);
		t++;
		fat++;
	}
}

void fatRead(struct file* readfile, char buffer, int bytes_read){
	esp_printf((void*)putc, "\nRDE cluster: %d \n", readfile->rde.cluster);

	int first_root_directory = bs->num_reserved_sectors + (bs->num_fat_tables * bs->num_sectors_per_fat) + ((bs->num_root_dir_entries * 32) + (bs->bytes_per_sector - 1)) / bs->bytes_per_sector;
	int first_sector = first_root_directory + ((readfile->rde.cluster - 2) * bs->num_sectors_per_cluster);

	char rbbuffer[512];
	sd_readblock(first_sector,rbbuffer,1);

	esp_printf((void*)putc, "Readblock: %s \n", rbbuffer);
	esp_printf((void*)putc, "First root directory: %d \n", first_root_directory);
	esp_printf((void*)putc, "First sector: %d \n", first_sector);
}

