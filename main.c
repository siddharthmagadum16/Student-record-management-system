#include <stdlib.h>
#include <sys/types.h> //"sys/" part means there's a "sys" directory where the standard header files are, and types.h can be found there.
#include <signal.h>// defines how a program handles various signals while it executes
#include <unistd.h>		// provides access to the POSIX operating system API
#include <string.h>
#include <gtk/gtk.h>    // used for GUI
#include <gtk/gtkx.h>
#include <math.h>		// for mathematical tools
#include <ctype.h>		// used for charater classification
#include <stdio.h>

struct student
	{
		char name[20];
		char sec[10];
		char srn[20],cycle[10],grade[5];
		char esa[10];
	}s[100];
struct markes
{
	char eceee[10],phychem[10],mechcv[10],math[10],cs[10],cagbio[10];
}sm[100];

int count=2,search = 0,lines1=0;
const char *username,*password,*username1,*password1;
GtkWidget	*window;
GtkWidget	*fixed1;
GtkWidget   *frame1;		// gtk datatypes. stored in the form of pointers
GtkWidget   *frame2;
GtkWidget   *frame3;
GtkWidget	*button1;
GtkWidget	*label1;
GtkWidget	*name1;
GtkWidget	*srn1;
GtkWidget	*sec1;
GtkWidget	*cycle1;
GtkWidget	*esa1;
GtkWidget   *grade1;
GtkWidget   *entry1;
GtkWidget   *entry2;
GtkWidget   *addname;
GtkWidget   *addsrn;
GtkWidget   *addsec;
GtkWidget   *addcycle;
GtkWidget   *addesa;
GtkWidget   *addgrade;
GtkWidget   *ECEEE;
GtkWidget   *PHYCHEM;
GtkWidget   *MECHCV;
GtkWidget   *MATH;
GtkWidget   *CS;
GtkWidget   *CAGBIO;
GtkWidget   *entrye;
GtkWidget   *entrypc;
GtkWidget   *entrymc;
GtkWidget   *entrym;
GtkWidget   *entryc;
GtkWidget   *entrycb;
GtkWidget   *btnmark;
GtkWidget   *total;

GtkWidget   *modiname;
GtkWidget   *modiname1;
GtkWidget   *modisrn;
GtkWidget   *modisec;
GtkWidget   *modicycle;
GtkWidget   *modiesa;
GtkWidget   *modigrade;
GtkWidget   *btnmodi;
GtkWidget   *btnmodisearch;
GtkWidget   *modisrn1;

GtkWidget   *entryme;
GtkWidget   *entryph;
GtkWidget   *entryec;
GtkWidget   *entrymath;
GtkWidget   *entrycs;
GtkWidget   *entrycag;

GtkWidget   *entme;
GtkWidget   *entph;
GtkWidget   *entec;
GtkWidget   *entmath;
GtkWidget   *entcs;
GtkWidget   *entcag;

GtkWidget   *labme;
GtkWidget   *labph;
GtkWidget   *labec;
GtkWidget   *labmath;
GtkWidget   *labcs;
GtkWidget   *labcag;



GtkWidget   *btnstore;
GtkWidget   *delmodi;
GtkBuilder	*builder;

G_MODULE_EXPORT void on_button1_clicked (GtkButton *b); 
G_MODULE_EXPORT void on_btnstore_clicked (GtkButton *b);
G_MODULE_EXPORT void on_btnmark_clicked (GtkButton *b);				//function prototypes...
G_MODULE_EXPORT void on_btnmodisearch_clicked (GtkButton *b);
G_MODULE_EXPORT void on_btnmodi_clicked (GtkButton *b);
G_MODULE_EXPORT void on_delmodi_clicked (GtkButton *b);

int main(int argc, char *argv[]) {

	
	FILE *fp2;
	fp2=fopen("data.txt","r");
	int countlines=0;
	char cha=fgetc(fp2);
	while(cha!=EOF){
		if(cha=='\n')	countlines++;
		cha=fgetc(fp2);
	}
	lines1=countlines;
	gtk_init(&argc, &argv); // init Gtk

//---------------------------------------------------------------------
// establish contact with xml code used to adjust widget settings
//---------------------------------------------------------------------
 
	builder = gtk_builder_new_from_file ("main.glade");
 
	window = GTK_WIDGET(gtk_builder_get_object(builder, "window"));

	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
	gtk_builder_connect_signals(builder, NULL);
        

	fixed1 = GTK_WIDGET(gtk_builder_get_object(builder, "fixed1"));
	button1 = GTK_WIDGET(gtk_builder_get_object(builder, "button1"));
	frame1 = GTK_WIDGET(gtk_builder_get_object(builder, "frame1"));
	frame2 = GTK_WIDGET(gtk_builder_get_object(builder, "frame2"));
	frame3 = GTK_WIDGET(gtk_builder_get_object(builder, "frame3"));
	name1 = GTK_WIDGET(gtk_builder_get_object(builder, "name1"));
	srn1 = GTK_WIDGET(gtk_builder_get_object(builder, "srn1"));
	sec1 = GTK_WIDGET(gtk_builder_get_object(builder, "sec1"));
	cycle1 = GTK_WIDGET(gtk_builder_get_object(builder, "cycle1"));
	esa1 = GTK_WIDGET(gtk_builder_get_object(builder, "esa1"));
	entry1 = GTK_WIDGET(gtk_builder_get_object(builder, "entry1"));
	entry2 = GTK_WIDGET(gtk_builder_get_object(builder, "entry2"));
	grade1 = GTK_WIDGET(gtk_builder_get_object(builder, "grade1"));
	
	ECEEE = GTK_WIDGET(gtk_builder_get_object(builder, "ECEEE"));
	PHYCHEM = GTK_WIDGET(gtk_builder_get_object(builder, "PHYCHEM"));
	MECHCV = GTK_WIDGET(gtk_builder_get_object(builder, "MECHCV"));
	MATH = GTK_WIDGET(gtk_builder_get_object(builder, "MATH"));
	CS = GTK_WIDGET(gtk_builder_get_object(builder, "CS"));
	CAGBIO = GTK_WIDGET(gtk_builder_get_object(builder, "CAGBIO")); 
	total = GTK_WIDGET(gtk_builder_get_object(builder, "total")); 


	entrye = GTK_WIDGET(gtk_builder_get_object(builder, "entrye"));
	entrypc = GTK_WIDGET(gtk_builder_get_object(builder, "entrypc"));
	entrymc = GTK_WIDGET(gtk_builder_get_object(builder, "entrymc"));
	entrym = GTK_WIDGET(gtk_builder_get_object(builder, "entrym"));
	entryc = GTK_WIDGET(gtk_builder_get_object(builder, "entryc"));
	entrycb = GTK_WIDGET(gtk_builder_get_object(builder, "entrycb"));

	entryec = GTK_WIDGET(gtk_builder_get_object(builder, "entryec"));
	entryph = GTK_WIDGET(gtk_builder_get_object(builder, "entryph"));
	entryme = GTK_WIDGET(gtk_builder_get_object(builder, "entryme"));
	entrymath = GTK_WIDGET(gtk_builder_get_object(builder, "entrymath"));
	entrycs = GTK_WIDGET(gtk_builder_get_object(builder, "entrycs"));
	entrycag = GTK_WIDGET(gtk_builder_get_object(builder, "entrycag"));	

	entec = GTK_WIDGET(gtk_builder_get_object(builder, "entec"));
	entph = GTK_WIDGET(gtk_builder_get_object(builder, "entph"));
	entme = GTK_WIDGET(gtk_builder_get_object(builder, "entme"));
	entmath = GTK_WIDGET(gtk_builder_get_object(builder, "entmath"));
	entcs = GTK_WIDGET(gtk_builder_get_object(builder, "entcs"));
	entcag = GTK_WIDGET(gtk_builder_get_object(builder, "entcag"));

	labec = GTK_WIDGET(gtk_builder_get_object(builder, "labec"));
	labph = GTK_WIDGET(gtk_builder_get_object(builder, "labph"));
	labme = GTK_WIDGET(gtk_builder_get_object(builder, "labme"));
	labmath = GTK_WIDGET(gtk_builder_get_object(builder, "labmath"));
	labcs = GTK_WIDGET(gtk_builder_get_object(builder, "labcs"));
	labcag = GTK_WIDGET(gtk_builder_get_object(builder, "labcag"));


	addname = GTK_WIDGET(gtk_builder_get_object(builder, "addname"));
	addsrn = GTK_WIDGET(gtk_builder_get_object(builder, "addsrn"));
	addsec = GTK_WIDGET(gtk_builder_get_object(builder, "addsec"));
	addcycle = GTK_WIDGET(gtk_builder_get_object(builder, "addcycle"));
	addesa = GTK_WIDGET(gtk_builder_get_object(builder, "addesa"));
	addgrade = GTK_WIDGET(gtk_builder_get_object(builder, "addgrade"));
	btnstore = GTK_WIDGET(gtk_builder_get_object(builder, "btnstore"));
	
	modiname = GTK_WIDGET(gtk_builder_get_object(builder, "modiname"));
	modiname1 = GTK_WIDGET(gtk_builder_get_object(builder, "modiname1"));
	modisrn = GTK_WIDGET(gtk_builder_get_object(builder, "modisrn"));
	modisrn1 = GTK_WIDGET(gtk_builder_get_object(builder, "modisrn1"));
	modisec = GTK_WIDGET(gtk_builder_get_object(builder, "modisec"));
	modicycle = GTK_WIDGET(gtk_builder_get_object(builder, "modicycle"));
	modiesa = GTK_WIDGET(gtk_builder_get_object(builder, "modiesa"));
	modigrade = GTK_WIDGET(gtk_builder_get_object(builder, "modigrade"));
	btnmodisearch = GTK_WIDGET(gtk_builder_get_object(builder, "btnmodisearch"));
	btnmodi = GTK_WIDGET(gtk_builder_get_object(builder, "btnmodi"));

	gtk_label_set_text (GTK_LABEL(name1), "student name");
	gtk_label_set_text (GTK_LABEL(srn1),  "student srn");
	gtk_label_set_text (GTK_LABEL(sec1),  "student sec");
	gtk_label_set_text (GTK_LABEL(cycle1),  "student cycle");
	gtk_label_set_text (GTK_LABEL(esa1),  "eas markes");
	gtk_label_set_text (GTK_LABEL(grade1),  "eas grade");

	gtk_widget_show(window);

	gtk_main();

	return EXIT_SUCCESS;
	}

void on_button1_clicked (GtkButton *b) {
	struct student s1[10];
	struct markes sm1[10]; 
	FILE *fp;
	fp = fopen("data.text","r");
	for (int i = 0; i < 10; i++)
	{
		fscanf(fp,"%s",s1[i].name);
	g_print("%s",s1[i].name);
	fscanf(fp,"%s",s1[i].srn);
	fscanf(fp,"%s",s1[i].sec);
	fscanf(fp,"%s",s1[i].cycle);
	fscanf(fp,"%s",s1[i].esa);
	fscanf(fp,"%s",s1[i].grade);

		fscanf(fp,"%s",sm1[i].eceee);
	g_print("%s",sm1[i].eceee);
	fscanf(fp,"%s",sm1[i].phychem);
	fscanf(fp,"%s",sm1[i].mechcv);
	fscanf(fp,"%s",sm1[i].math);
	fscanf(fp,"%s",sm1[i].cs);
	fscanf(fp,"%s",sm1[i].cagbio);
	}
	
	//fprintf(fp, "\n" );
	fclose(fp);	

	username = gtk_entry_get_text(GTK_ENTRY(entry1));
	password = gtk_entry_get_text(GTK_ENTRY(entry2));
	g_print("Entry text: '%s'\n", username);
	g_print("Entry text: '%s'\n", password);
	for (int i = 0; i < 20; ++i)
	{
		if ( !strcmp(username,s1[i].name) && !strcmp(password,s1[i].srn) ){
		g_print("logined scucces\n");	
		gtk_label_set_text (GTK_LABEL(name1), s1[i].name);
		gtk_label_set_text (GTK_LABEL(srn1),  s1[i].srn);
		gtk_label_set_text (GTK_LABEL(sec1),  s1[i].sec);
		gtk_label_set_text (GTK_LABEL(cycle1),  s1[i].cycle);
		gtk_label_set_text (GTK_LABEL(esa1),  s1[i].esa);
		gtk_label_set_text (GTK_LABEL(grade1),  s1[i].grade);

		if (!strcmp(s1[i].cycle,"physics"))
		{
			gtk_label_set_text (GTK_LABEL(labph), "physics");
		gtk_label_set_text (GTK_LABEL(labec),  "EEE");
		gtk_label_set_text (GTK_LABEL(labme),  "MECH");
		gtk_label_set_text (GTK_LABEL(labmath),  "MATH");
		gtk_label_set_text (GTK_LABEL(labcs),  "CS");
		gtk_label_set_text (GTK_LABEL(labcag),  "CAG");	
		}else {
			gtk_label_set_text (GTK_LABEL(labph), "Chemistry");
		gtk_label_set_text (GTK_LABEL(labec),  "EC");
		gtk_label_set_text (GTK_LABEL(labme),  "CV");
		gtk_label_set_text (GTK_LABEL(labmath),  "MATH");
		gtk_label_set_text (GTK_LABEL(labcs),  "CS");
		gtk_label_set_text (GTK_LABEL(labcag),  "BIO");
		}

		gtk_label_set_text (GTK_LABEL(entph), sm1[i].phychem);
		gtk_label_set_text (GTK_LABEL(entec),  sm1[i].eceee);
		gtk_label_set_text (GTK_LABEL(entmath),  sm1[i].math);
		gtk_label_set_text (GTK_LABEL(entme),  sm1[i].mechcv);
		gtk_label_set_text (GTK_LABEL(entcag),  sm1[i].cagbio);
		gtk_label_set_text (GTK_LABEL(entcs),  sm1[i].cs);

		
		
		} 	
	}
	

}


void on_btnstore_clicked (GtkButton *b){
	strcpy(s[count].name ,gtk_entry_get_text(GTK_ENTRY(addname)));
	strcpy(s[count].srn ,gtk_entry_get_text(GTK_ENTRY(addsrn)));
	strcpy(s[count].sec ,gtk_entry_get_text(GTK_ENTRY(addsec)));
	strcpy(s[count].cycle ,gtk_entry_get_text(GTK_ENTRY(addcycle)));
	strcpy(s[count].esa ,gtk_entry_get_text(GTK_ENTRY(addesa)));
	strcpy(s[count].grade ,gtk_entry_get_text(GTK_ENTRY(addgrade)));
	g_print("Entry text: '%s'\n", s[count].name);
	g_print("Entry text: '%s'\n", s[count].srn);
	g_print("Entry text: '%s'\n", s[count].sec);
	FILE *fp;

	fp = fopen("data.text","a");
	fprintf(fp, "%s\t",s[count].name );
	fprintf(fp, "%s\t",s[count].srn );
	fprintf(fp, "%s\t",s[count].sec );
	fprintf(fp, "%s\t",s[count].cycle );
	fprintf(fp, "%s\t",s[count].esa );
	fprintf(fp, "%s\t",s[count].grade );
	//fprintf(fp, "\n" );
	fclose(fp);

	count++;
	
	if (!strcmp(gtk_entry_get_text(GTK_ENTRY(addcycle)),"physics"))
	{
			gtk_label_set_text (GTK_LABEL(ECEEE), "EEE");
			gtk_label_set_text (GTK_LABEL(PHYCHEM),  "PHY");
			gtk_label_set_text (GTK_LABEL(MECHCV),  "MECH");
			gtk_label_set_text (GTK_LABEL(MATH), "MATH");
			gtk_label_set_text (GTK_LABEL(CS), "CS");
			gtk_label_set_text (GTK_LABEL(CAGBIO), "CAG");	
	}else if (!strcmp(gtk_entry_get_text(GTK_ENTRY(addcycle)),"chemistry")){
			gtk_label_set_text (GTK_LABEL(ECEEE), "EC");
			gtk_label_set_text (GTK_LABEL(PHYCHEM),  "CHEM");
			gtk_label_set_text (GTK_LABEL(MECHCV),  "CV");
			gtk_label_set_text (GTK_LABEL(MATH), "MATH");
			gtk_label_set_text (GTK_LABEL(CS), "CS");
			gtk_label_set_text (GTK_LABEL(CAGBIO), "BIO");	
	} else {
			gtk_label_set_text (GTK_LABEL(ECEEE), "EC/EEE");
			gtk_label_set_text (GTK_LABEL(PHYCHEM),  "PHY/CHEM");
			gtk_label_set_text (GTK_LABEL(MECHCV),  "MECH/CV");
			gtk_label_set_text (GTK_LABEL(MATH), "MATH");
			gtk_label_set_text (GTK_LABEL(CS), "CS");
			gtk_label_set_text (GTK_LABEL(CAGBIO), "CAG/BIO");	
	}

	lines1++;

}


void on_btnmark_clicked (GtkButton *b){
	//res=atoi(res1)

	char res1[10];
	strcpy(sm[count].phychem ,gtk_entry_get_text(GTK_ENTRY(entrypc)));
	strcpy(sm[count].eceee ,gtk_entry_get_text(GTK_ENTRY(entrye)));
	strcpy(sm[count].mechcv ,gtk_entry_get_text(GTK_ENTRY(entrymc)));
	strcpy(sm[count].math ,gtk_entry_get_text(GTK_ENTRY(entrym)));
	strcpy(sm[count].cs ,gtk_entry_get_text(GTK_ENTRY(entryc)));
	strcpy(sm[count].cagbio ,gtk_entry_get_text(GTK_ENTRY(entrycb)));
	g_print("Entry text: '%s'\n", sm[count].phychem);
	g_print("Entry text: '%s'\n", sm[count].eceee);
	g_print("Entry text: '%s'\n", sm[count].mechcv);
	
	FILE *fp;

	fp = fopen("data.text","a");
	fprintf(fp, "%s\t",sm[count].phychem );
	fprintf(fp, "%s\t",sm[count].eceee );
	fprintf(fp, "%s\t",sm[count].mechcv );
	fprintf(fp, "%s\t",sm[count].math );
	fprintf(fp, "%s\t",sm[count].cs );
	fprintf(fp, "%s\t",sm[count].cagbio );
	fprintf(fp, "\n" );
	fclose(fp);

	int res,pc=atoi(sm[count].phychem),e=atoi(sm[count].eceee),mc=atoi(sm[count].mechcv),m=atoi(sm[count].math),c=atoi(sm[count].cs),cb=atoi(sm[count].cagbio);
	res = pc+e+mc+m+c+cb;
	itoa(res,res1,10);
	gtk_label_set_text (GTK_LABEL(total), res1);
}


void on_btnmodisearch_clicked (GtkButton *b){
	struct student s1[10];
	struct markes sm1[10]; 
	FILE *fp;
	fp = fopen("data.text","r");
	for (int i = 0; i < 10; i++)
	{
	g_print("%s",s1[i].name);
		fscanf(fp,"%s",s1[i].name);
		fscanf(fp,"%s",s1[i].srn);
		fscanf(fp,"%s",s1[i].sec);
		fscanf(fp,"%s",s1[i].cycle);
		fscanf(fp,"%s",s1[i].esa);
		fscanf(fp,"%s",s1[i].grade);
		g_print("%s",sm1[i].eceee);
		fscanf(fp,"%s",sm1[i].eceee);
		fscanf(fp,"%s",sm1[i].phychem);
		fscanf(fp,"%s",sm1[i].mechcv);
		fscanf(fp,"%s",sm1[i].math);
		fscanf(fp,"%s",sm1[i].cs);
		fscanf(fp,"%s",sm1[i].cagbio);
	}

	fclose(fp);	

	username1 = gtk_entry_get_text(GTK_ENTRY(modiname1));
	password1 = gtk_entry_get_text(GTK_ENTRY(modisrn1));
	g_print("Entry text: '%s'\n", username);
	g_print("Entry text: '%s'\n", password);
	for (int i = 0; i < 20; ++i)
	{
		if ( !strcmp(username1,s1[i].name) || !strcmp(password1,s1[i].srn) ){
		g_print("logined success\n");	
		gtk_entry_set_text (GTK_ENTRY(modiname), s1[i].name);
		gtk_entry_set_text (GTK_ENTRY(modisrn),  s1[i].srn);
		gtk_entry_set_text (GTK_ENTRY(modisec),  s1[i].sec);
		gtk_entry_set_text (GTK_ENTRY(modicycle),  s1[i].cycle);
		gtk_entry_set_text (GTK_ENTRY(modiesa),  s1[i].esa);
		gtk_entry_set_text (GTK_ENTRY(modigrade),  s1[i].grade);
		
		gtk_entry_set_text (GTK_ENTRY(entryec), sm1[i].eceee);
		gtk_entry_set_text (GTK_ENTRY(entryph),  sm1[i].phychem);
		gtk_entry_set_text (GTK_ENTRY(entryme),  sm1[i].mechcv);
		gtk_entry_set_text (GTK_ENTRY(entrymath),  sm1[i].math);
		gtk_entry_set_text (GTK_ENTRY(entrycs),  sm1[i].cs);
		gtk_entry_set_text (GTK_ENTRY(entrycag),  sm1[i].cagbio);
		search = i;
		} 	
	}
}

void on_btnmodi_clicked (GtkButton *b){
	
	struct student s[10];
	struct markes sm[10]; 
	FILE *fp;
	fp = fopen("data.text","r");
	for (int i = 0; i < 10; i++)
	{
		fscanf(fp,"%s",s[i].name);
	g_print("%s",s[i].name);
	fscanf(fp,"%s",s[i].srn);
	fscanf(fp,"%s",s[i].sec);
	fscanf(fp,"%s",s[i].cycle);
	fscanf(fp,"%s",s[i].esa);
	fscanf(fp,"%s",s[i].grade);

		fscanf(fp,"%s",sm[i].eceee);
	g_print("%s",sm[i].eceee);
	fscanf(fp,"%s",sm[i].phychem);
	fscanf(fp,"%s",sm[i].mechcv);
	fscanf(fp,"%s",sm[i].math);
	fscanf(fp,"%s",sm[i].cs);      
	fscanf(fp,"%s",sm[i].cagbio);
	}
	
	//fprintf(fp, "\n" );
	fclose(fp);
	strcpy(s[search].name ,gtk_entry_get_text(GTK_ENTRY(modiname)));
	strcpy(s[search].srn ,gtk_entry_get_text(GTK_ENTRY(modisrn)));
	strcpy(s[search].sec ,gtk_entry_get_text(GTK_ENTRY(modisec)));
	strcpy(s[search].cycle ,gtk_entry_get_text(GTK_ENTRY(modicycle)));
	strcpy(s[search].esa ,gtk_entry_get_text(GTK_ENTRY(modiesa)));
	strcpy(s[search].grade ,gtk_entry_get_text(GTK_ENTRY(modigrade)));
	g_print("Entry text: '%s'\n", s[search].name);
	g_print("Entry text: '%s'\n", s[search].srn);
	g_print("Entry text: '%s'\n", s[search].sec);



	strcpy(sm[search].phychem ,gtk_entry_get_text(GTK_ENTRY(entryph)));
	strcpy(sm[search].eceee ,gtk_entry_get_text(GTK_ENTRY(entryec)));
	strcpy(sm[search].mechcv ,gtk_entry_get_text(GTK_ENTRY(entryme)));
	strcpy(sm[search].math ,gtk_entry_get_text(GTK_ENTRY(entrymath)));
	strcpy(sm[search].cs ,gtk_entry_get_text(GTK_ENTRY(entrycs)));
	strcpy(sm[search].cagbio ,gtk_entry_get_text(GTK_ENTRY(entrycag)));
	g_print("Entry text: '%s'\n", sm[search].phychem);
	g_print("Entry text: '%s'\n", sm[search].eceee);
	g_print("Entry text: '%s'\n", sm[search].mechcv);

	FILE *fp1;

	for (int i = 0; i < 10; ++i)
	{
		g_print("\n%s\n",s[i].name);
		g_print("%s\n",s[i].srn);
		g_print("%s\n",s[i].sec);
		g_print("%s\n",s[i].cycle);
		g_print("%s\n",s[i].esa);
		g_print("%s\n",s[i].grade);
		
		g_print("\n%s\n",sm[i].phychem);
		g_print("%s\n",sm[i].eceee);
		g_print("%s\n",sm[i].mechcv);
		g_print("%s\n",sm[i].math);
		g_print("%s\n",sm[i].cs);
		g_print("%s\n",sm[i].cagbio);
		
	}

	fp1 = fopen("data.text","w");
	for (int i = 0; i < 4; ++i)
	{
	fprintf(fp, "%s\t",s[i].name );
	fprintf(fp, "%s\t",s[i].srn );
	fprintf(fp, "%s\t",s[i].sec );
	fprintf(fp, "%s\t",s[i].cycle );
	fprintf(fp, "%s\t",s[i].esa );
	fprintf(fp, "%s\t",s[i].grade );
	
	fprintf(fp, "%s\t",sm[i].phychem );
	fprintf(fp, "%s\t",sm[i].eceee );
	fprintf(fp, "%s\t",sm[i].mechcv );
	fprintf(fp, "%s\t",sm[i].math );
	fprintf(fp, "%s\t",sm[i].cs );
	fprintf(fp, "%s\t",sm[i].cagbio );
	fprintf(fp, "\n" );

	}
	
	
	fclose(fp1);
	

}

//__________________________________________________________________________________________



void on_delmodi_clicked (GtkButton *b){
	
	struct student s1[10];
	struct markes sm1[10];
	// char a[100"; 
	FILE *fp;
	fp = fopen("data.text","r");
	for (int i = 0; i <lines1; i++){
		fscanf(fp,"%s",s1[i].name);
		fscanf(fp,"%s",s1[i].srn);
		fscanf(fp,"%s",s1[i].sec);
		fscanf(fp,"%s",s1[i].cycle);
		fscanf(fp,"%s",s1[i].esa);
		fscanf(fp,"%s",s1[i].grade);
		g_print("%s",sm1[i].eceee);
		fscanf(fp,"%s",sm1[i].eceee);
		fscanf(fp,"%s",sm1[i].phychem);
		fscanf(fp,"%s",sm1[i].mechcv);
		fscanf(fp,"%s",sm1[i].math);
		fscanf(fp,"%s",sm1[i].cs);
		fscanf(fp,"%s",sm1[i].cagbio);
	}
	fclose(fp); 	FILE *fp1;
	for (int i = 0; i < lines1; ++i)
	{
		g_print("\n%s\n",s[i].name);
		g_print("%s\n",s1[i].srn);	
		g_print("%s\n",s1[i].sec);	
		g_print("%s\n",s1[i].cycle);	
		g_print("%s\n",s1[i].esa);	
		g_print("%s\n",s1[i].grade);	

		g_print("\n%s\n",sm1[i].phychem);
		g_print("%s\n",sm1[i].eceee);
		g_print("%s\n",sm1[i].mechcv);
		g_print("%s\n",sm1[i].math);
		g_print("%s\n",sm1[i].cs);
		g_print("%s\n",sm1[i].cagbio);	
	}
	fp1 = fopen("data.text","w");
	g_print(" 		lines1:%d\n",lines1);
	for (int i = 0; i < lines1; ++i)
	{	if(i!=search){
			fprintf(fp, "%s\t",s1[i].name );
			fprintf(fp, "%s\t",s1[i].srn );
			fprintf(fp, "%s\t",s1[i].sec );
			fprintf(fp, "%s\t",s1[i].cycle );
			fprintf(fp, "%s\t",s1[i].esa );
			fprintf(fp, "%s\t",s1[i].grade );

			fprintf(fp, "%s\t",sm1[i].phychem );
			fprintf(fp, "%s\t",sm1[i].eceee );
			fprintf(fp, "%s\t",sm1[i].mechcv );
			fprintf(fp, "%s\t",sm1[i].math );
			fprintf(fp, "%s\t",sm1[i].cs );
			fprintf(fp, "%s\t",sm1[i].cagbio );
			fprintf(fp, "\n" );
		}
	}	
	fclose(fp1);
	lines1--;
}