#include<stdio.h>
#define MAX_PAGES 50
#define MAX_FRAMES 10
int main() {
        int pages[MAX_PAGES],frames[MAX_FRAMES];
        int num_pages, num_frames;
        int choice;
        int page_faults = 0;
        int is_page_in_memory;
        printf("Enter  the number of Pages: ");
        scanf("%d",&num_pages);
        printf("Enter the page numbers: \n");
        for (int i=0; i<num_pages; i++){
                scanf("%d",&pages[i]);
        }
        printf("Enter the number of frames: ");
        scanf("%d",&num_frames);
        for (int i=0; i<num_frames; i++){
                frames[i]=-1;
        }
        int j = 0;
        printf("RefString\tPageElements\n");
        for (int i=0; i<num_pages; i++){
                printf("%d\t\t",pages[i]);
                is_page_in_memory = 0;
                for (int k=0; k<num_frames; k++){
                        if(frames[k]==pages[i]){
                                is_page_in_memory = 1;
                                break;
                        }
                }
                if(!is_page_in_memory) {
                        frames[j]=pages[i];
                        j=(j+1)%num_frames;
                        page_faults++;
                }
                for (int k=0; k<num_frames; k++){
                        printf("%d\t", frames[k]);
                }
                printf("\n");
        }
        printf("Total number of Page faults : %d\n",page_faults);
        printf("Total Percentage of Page faults: %.2f\n",((double)page_faults/num_pages*100));
        printf("Total number of Page Hits : %d\n", num_pages-page_faults);
        printf("Total Percentage of Page Hits: %.2f\n",((double)(num_pages-page_faults)/num_pages*100));
}
