#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void ch_elf(unsigned char *e_id);
void pr_mag(unsigned char *e_id);
void pr_cl(unsigned char *e_id);
void pr_da(unsigned char *e_id);
void pr_ver(unsigned char *e_id);
void pr_abi(unsigned char *e_id);
void pr_os(unsigned char *e_id);
void pr_ty(unsigned int e_ty, unsigned char *e_id);
void pr_en(unsigned long int e_en, unsigned char *e_id);
void cl_elf(int e);

/**
 * ch_elf - Checks if file were ELF file.
 * @e_id: A pointer to array contain ELF magic number.
 * If the file not ELF file - exit code 98.
 */
void ch_elf(unsigned char *e_id)
{
	int in;

	for (in = 0; in < 4; in++)
	{
		if (e_id[in] != 127 &&
		    e_id[in] != 'E' &&
		    e_id[in] != 'L' &&
		    e_id[in] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * pr_mag- Print magicians number of ELF header.
 * @e_id: pointer an array contain the ELF magics number.
 * Desc: Magic numbers are separate spaces.
 */
void pr_mag(unsigned char *e_id)
{
	int in;

	printf(" Magic: ");

	for (in= 0; in < EI_NIDENT; in++)
	{
		printf("%02x", e_id[in]);

		if (in == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * pr_cl - Print class of ELF headers.
 * @e_id: pointer to array contains ELF classes.
 */
void pr_cl(unsigned char *e_id)
{
	printf(" Class: ");

	switch (e_id[EI_CLASS])
	{
	case ELFCLASSNONE:
		printf("none\n");
		break;
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("<unknown: %x>\n", e_id[EI_CLASS]);
	}
}

/**
 * pr_da - Print data of ELF headers.
 * @e_id: pointer to array contains  ELF classes.
 */
void pr_da(unsigned char *e_id)
{
	printf(" Data: ");

	switch (e_id[EI_DATA])
	{
	case ELFDATANONE:
		printf("none\n");
		break;
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("<unknown: %x>\n", e_id[EI_CLASS]);
	}
}

/**
 *  * pr_ver - Print versions of ELF headers.
 *   * @e_id: pointer array contains  ELF versions.    
*/
void pr_ver(unsigned char *e_id)
{
	 printf(" Version: %d",
			  e_id[EI_VERSION]);

	switch (e_id[EI_VERSION])
	{
	case EV_CURRENT:
		printf(" (current)\n");
		break;
	default:
		printf("\n");
		break;
	}
}

/**
 * pr_os - Print OS/ABI of ELF headers.
 * @e_id: pointer  array contains ELF versions.
 */
void pr_os(unsigned char *e_id)
{
	printf(" OS/ABI: ");

	switch (e_id[EI_OSABI])
	{
	case ELFOSABI_NONE:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;
	case ELFOSABI_ARM:
		printf("ARM\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Standalone App\n");
		break;
	default:
		printf("<unknown: %x>\n", e_id[EI_OSABI]);
	}
}

/**
 * pr_abi - Print ABI versions ELF headers.
 * @e_id: pointer array contains ELF ABI versions.
 */
void pr_abi(unsigned char *e_id)
{
	printf(" ABI Version: %d\n",
		e_id[EI_ABIVERSION]);
}

/**
 * pr_ty - Print  type ELF headers.
 * @e_ty: ELF types.
 * @e_id: pointer array contains  ELF classes.
 */
void pr_ty(unsigned int e_ty, unsigned char *e_id)
{
	if (e_id[EI_DATA] == ELFDATA2MSB)
		e_ty >>= 8;

	printf(" Type: ");

	switch (e_ty)
	{
	case ET_NONE:
		printf("NONE (None)\n");
		break;
	case ET_REL:
		printf("REL (Relocatable file)\n");
		break;
	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
	case ET_CORE:
		printf("CORE (Core file)\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ty);
	}
}

/**
 * pr_en - Prints entry point ELF headers.
 * @e_en: address ELF entry point.
 * @e_id: pointer  array contains ELF classes.
 */
void pr_en(unsigned long int e_en, unsigned char *e_id)
{
	printf(" Entry point address: ");

	if (e_id[EI_DATA] == ELFDATA2MSB)
	{
		e_en = ((e_en << 8) & 0xFF00FF00) |
			  ((e_en >> 8) & 0xFF00FF);
		e_en = (e_en << 16) | (e_en >> 16);
	}

	if (e_id[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_en);

	else
		printf("%#lx\n", e_en);
}

/**
 * cl_elf - Closes ELF files.
 * @e: file descriptor ELF files.
 * Description: If file can’t be closed exit code 98.
 */
void cl_elf(int e)
{
	if (close(e) == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't close fd %d\n", e);
		exit(98);
	}
}

/**
 * main Display informations contain in 
 * ELF headers start of ELF files.
 * @a_c: number arguments supply programs.
 * @a_v:  arrays pointer arguments.
 * Returns: 0 on succes.
 * Description: If file not  ELF File or
 * function fails  exit code 98.
 */
int main(int __attribute__((__unused__)) a_c, char *a_v[])
{
	Elf64_Ehdr *h;
	int a, b;

	a = open(a_v[1], O_RDONLY);
	if (a == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", a_v[1]);
		exit(98);
	}
	h = malloc(sizeof(Elf64_Ehdr));
	if (h == NULL)
	{
		cl_elf(a);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", a_v[1]);
		exit(98);
	}
	b = read(a, h, sizeof(Elf64_Ehdr));
	if (b == -1)
	{
		free(h);
		cl_elf(a);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", a_v[1]);
		exit(98);
	}
	
	ch_elf(h->e_ident);
	printf("ELF Header:\n");
	pr_mag(h->e_ident);
	pr_cl(h->e_ident);
	pr_da(h->e_ident);
	pr_ver(h->e_ident);
	pr_os(h->e_ident);
	pr_abi(h->e_ident);
	pr_ty(h->e_type, h->e_ident);
	pr_en(h->e_entry, h->e_ident);

	free(h);
	cl_elf(a);
	return (0);
}
