#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"list_header.h"






pd *start, *new, *ptr, *prev,*last;
ct *start1,*new1,*ptr1,*prev1,*last1;
t *start2,*new2,*ptr2,*prev2,*last2;


/*******************************************************************************************
 *
 *   *FUNCTION NAME  :  product_registrtion
 *
 *   *DESCRIPTION    :  This functions is used here for registration  and to add the new product
 *                        by the product or by the Admin respectively.
 *
 *   *RETURNS        :  No Returns
 *
 *******************************************************************************************/


int product_registration()
{
	if((new=(pd*)calloc(1,sizeof(pd)))==NULL)
	{
		printf("\nMemory Allocation failed\n");
		return EXIT_FAILURE;
	}

	while(1)
	{
		printf("\n----------WELCOME TO PRODUCT REGISTRATION-------\n");
		while(1)
		{
			printf("Enter Restaurant Name: ");
			scanf("%s",new->productName);
			if(validate_name(new->productName))
				continue;
			break;
		}
		while(1)
		{
			printf("Enter product id: ");
			scanf("%lld",&new->productid);
			if(validate_product_id(new->productid))
				continue;
			break;
		}
		if(start)
		{
			for(ptr=start;(ptr) && ptr->productid!=new->productid;ptr=ptr->next);
			if(ptr)
			{
				printf("\nproduct id %lld is duplicte\n",new->productid);
				return EXIT_FAILURE;
			}
			else
				break;
		}
		break;
	}
	printf("Enter any one category from the below given.\n");
	printf(" \n    1.Breakfast\n    2.lunch\n    3.Dinner\n");

	while(1)
	{
		printf("Enter Choice:  ");
		scanf("%d", &new->choice);
		if(new->choice==1)
		{
			strcpy( new->category,"Breakfast");
		}
		else if(new->choice==2)
		{
			strcpy(new->category,"lunch");
		}
		else if(new->choice==3)
		{
			strcpy(new->category,"Dinner");
		}
		else
		{
			printf("INVALID CHOICE....");
			printf("Enter choice between 1-3");
			continue;
		}
		break;
	}
	int res;
	while(1)
	{
		printf("\nEnter the no.of items to supply:  ");
		scanf("%d",&res);
		new->code=res;
		if(res<1 || res>4)
		{
			printf("\n NUMBER OF ITEMS TO SUPPLY SHOULD BETWEEN 1 TO 4.");
			continue;
		}
		else
		{



			for(int i=0;i<res;i++)
			{
				printf("enter the item name:  ");
				scanf("%s",new->item[i]);
				printf("enter the quantity for item: ");
				scanf("%d",&new->quantity[i]);
				printf("enter the price for item: ");
				scanf("%d",&new->price[i]);
			}
		}
		break;
	}
	if(!start)
	{
		start=new;
		new->next=NULL;
	}
	else if(new->productid<start->productid)
	{
		new->next=start;
		start=new;
	}
	else
	{
		for(ptr=start;(ptr) && ptr->productid<new->productid;prev=ptr,ptr=ptr->next);
		prev->next=new;
		new->next=ptr;
	}

	return EXIT_SUCCESS;


}

/*******************************************************************************************
 *
 *   *FUNCTION NAME  :  edit_product_details
 *
 *   *DESCRIPTION    :  This functions is used here to edit the datas of the product by the product
 *                        or by the Admin after the registration process.
 *
 *   *RETURNS        :  No Returns
 *
 *******************************************************************************************/


int edit_product_details()
{
	if(!start)
	{
		printf("\n Empty List\n");
		return EXIT_FAILURE;
	}
	long long int pid;
	while(1)
	{
		printf("\nEnter product id for editing: ");
		scanf("%lld",&pid);
		if(validate_product_id(pid))
			continue;
		break;
	}
	for(ptr=start;(ptr) && ptr->productid!=pid;ptr=ptr->next);
	if(!ptr)
	{
		printf("\nProduct id %lld not found\n",pid);
		return EXIT_FAILURE;

	}
	printf("Enter new name- ");
	scanf("%s",ptr->productName);
/*	printf("Enter new phoneno- ");
	scanf("%s",&ptr->phoneno);
	printf("Enter new password- ");
	scanf("%s",&ptr->password);*/
	printf("Enter any one category from the below given.\n");
	printf("\n    1.Breakfast\n    2.lunch\n    3.Dinner\n");
	printf("Enter choice-"); 
	scanf("%d", &ptr->choice);
	if(ptr->choice==1)
	{
		strcpy(ptr->category,"Breakfast");
	}
	else if(ptr->choice==2)
	{
		strcpy(ptr->category,"lunch");
	}
	else if(ptr->choice==3)
	{
		strcpy(ptr->category,"Dinner");
	}
	else
	{
		printf("INVALID CHOICE");
	}
	int res;
	printf("Enter no.of items  to supply: ");
	scanf("%d",&res);
	if(res<1 || res>4)
	{
		printf("\nNo. of items should lie between 1 to 4.\nPlease enter your choice  between 1-4.");



	}
	else
	{
		for(int i=0;i<res;i++)
		{
			printf("Enter the item name: ");
			scanf("%s",ptr->item[i]);
			printf("Enter the quantity of the item: ");
			scanf("%d",&ptr->quantity[i]);
			printf("Enter the price of the item: ");
			scanf("%d",&ptr->price[i]);
		}
		printf("\nThe items are displayed in Menu");
	}
	return EXIT_SUCCESS;

}

/*******************************************************************************************
 *
 *   *FUNCTION NAME  :  show_product
 *
 *   *DESCRIPTION    :  This functions is used here to displays the datas of the product by the product
 *                        or by the Admin.
 *
 *   *RETURNS        :  No Returns
 *
 *******************************************************************************************/


int show_product()
{
	if(!start)
	{
		printf("\n Empty List\n");
		return EXIT_FAILURE;
	}


	printf("\nPRODUCT ID     NAME CATEGORY     ITEM_NAME     QUANTITY   PRICE  \n");
	for(ptr=start;(ptr);ptr=ptr->next)
	{
		for(int i=0;i<ptr->code;i++)
		{
			printf("\n%lld        %4s      %3s     %3s      %3d    %3d  \n",ptr->productid,ptr->productName,ptr->category,ptr->item[i],ptr->quantity[i],ptr->price[i]);
		}
	}
	return EXIT_SUCCESS;
}

/*******************************************************************************************
 *
 *   *FUNCTION NAME  :  delete_product_data
 *
 *   *DESCRIPTION    :  This functions is used here to delete the datas of the product by the Admin.
 *
 *   *RETURNS        :  No Returns
 *
 *******************************************************************************************/



int delete_product_data()
{
	if(!start)
	{
		printf("\nEmpty List\n");
		return EXIT_FAILURE;
	}
	long long int  dproductid;
	while(1)
	{
		printf("\nEnter the productid for deleting-");
		scanf("%lld",&dproductid);
		if(validate_product_id(dproductid))
			continue;
		break;
	}
	if(dproductid==start->productid)
	{
		ptr=start;
		start=start->next;
		free(ptr);
	}
	else
	{
		for(ptr=start;(ptr) && ptr->productid!=dproductid;prev=ptr,ptr=ptr->next);
		if(!ptr)
		{
			printf("\nProductid %lld is not found\n",dproductid);
			return EXIT_FAILURE;
		}
		prev->next=ptr->next;
		free(ptr);
	}
	return EXIT_SUCCESS;
}


/*******************************************************************************************
 *
 *   *FUNCTION NAME  :  product_to_list
 *
 *   *DESCRIPTION    :  This functions is used here to transfer the datas of the product from 
 *                           the product file to the list.
 *
 *   *RETURNS        :  No Returns
 *
 *******************************************************************************************/


int product_to_list()
{
	FILE *p;
	pdt f1;
	if((p=fopen("../data/Product.data","rb"))==NULL)
	{
		printf("\nFile is not there to read from\n");
		return EXIT_FAILURE;
	}
	fread(&f1,sizeof(pdt),1,p);
	while(!feof(p))
	{
		if((new=(pd *)calloc(1,sizeof(pd)))==NULL)
		{
			printf("\nMemory Allocation failed\n");
			return EXIT_FAILURE;
		}
		new->productid=f1.productid;
		strcpy(new->productName,f1.productName);
		new->phoneno=f1.phoneno;
		strcpy(new->password,f1.password);
		strcpy(new->category,f1.category);
		new->code=f1.code;
		for(int i=0;i<f1.code;i++)
		{
			strcpy(new->item[i],f1.item[i]);
			new->quantity[i]=f1.quantity[i];
			new->price[i]=f1.price[i];
		}
		if(!start)
		{
			start = last = new;
			new->next=NULL;
		}
		else
		{
			last->next=new;
			last=new;
			new->next=NULL;
		}
		fread(&f1,sizeof(pdt),1,p);
	}
	//    free(new);
	fclose(p);
	return EXIT_SUCCESS;
}                                                                      //product to list function ends here....

/*******************************************************************************************
 *
 *   *FUNCTION NAME  :  list_to_product
 *
 *   *DESCRIPTION    :  This functions is used here to transfer the data of the product from 
 *                           the list to the product file.
 *
 *   *RETURNS        :  No Returns
 *
 *******************************************************************************************/



int list_to_product()
{
	pdt f2;
	if(!start)
	{
		printf("\nThe List is Empty.\n");
		return EXIT_FAILURE;
	}
	FILE *p1;
	if((p1=fopen("../data/Product.data","wb"))==NULL)
	{
		printf("\nFile is not there to read from\n");
		return EXIT_FAILURE;
	}
	for(ptr=start;(ptr);ptr=ptr->next)
	{
		f2.productid=ptr->productid;
		strcpy(f2.productName,ptr->productName);
		f2.phoneno=ptr->phoneno;
		strcpy(f2.password,ptr->password);
		strcpy(f2.category,ptr->category);
		f2.code=ptr->code;
		for(int i=0;i<f2.code;i++)
		{
			strcpy(f2.item[i],ptr->item[i]);
			f2.quantity[i]=ptr->quantity[i];
			f2.price[i]=ptr->price[i];
		}
		fwrite(&f2,sizeof(pdt),1,p1);
	}
	fclose(p1);
	//    free(ptr);
	return EXIT_SUCCESS;
}                                                                                   //list to product function ends here....

/*******************************************************************************************
 *
 *   *FUNCTION NAME  :  registration
 *
 *   *DESCRIPTION    :  This functions is used here for the registration of the new customers
 *                      and adding of new customers by the customer itself and by the Admin respectively.
 *
 *   *RETURNS        :  No Returns
 *
 *******************************************************************************************/

int registration()
{
	if((new1=(ct *)calloc(1,sizeof(ct)))==NULL)
	{
		printf("\n Memory allocation failed\n");
		return EXIT_FAILURE;
	}
		while(1)
		{
		while(1)
		{
		printf("Enter the phoneno -");
		scanf("%lld",&new1->cphoneno);
		if(validate_phoneno(new1->cphoneno))
		continue;
		break;
		}	
		if(start1)
		{
		for(ptr1=start1;(ptr1) && ptr1->cphoneno!=new1->cphoneno;ptr1=ptr1->next1);
		if(ptr1)
		{
		printf("\nphone num  %lld is duplicate\n",new1->cphoneno);
		return EXIT_FAILURE;
		}
		else
		break;
		}
		break;
		}

	while(1)
	{

		printf("Enter the name-");
		scanf("%s",new1->customerName);
		if(validate_name(new1->customerName))
			continue;
		break;
	}
/*	while(1)
	{
		printf("Enter phone no-");
		scanf("%lld",&new1->cphoneno);
		if(validate_phoneno(new1->cphoneno))
			continue;
		break;
	}*/
	printf("Enter the address-");
	scanf("%s",new1->address);
		if(!start1)
		{
		start1=new1;
		new1->next1=NULL;
		}
		else if(new1->cphoneno<start1->cphoneno)
		{
		new1->next1=start1;
		start1=new1;
		}
		else
		{
		for(ptr1=start1;(ptr1) && ptr1->cphoneno<new1->cphoneno;prev1=ptr1,ptr1=ptr1->next1);
		prev1->next1=new1;
		new1->next1=ptr1;
		}
	return EXIT_SUCCESS;
}                                                                       //registration function ends here....

/*******************************************************************************************
 *
 *   *FUNCTION NAME  :  do_transaction
 *
 *   *DESCRIPTION    :  This functions is used here for the customers who needs to buy a product by
 *                           giving the product name and the respective items.
 *
 *   *RETURNS        :  No Returns
 *
 *******************************************************************************************/
int do_transaction()
{

	ct c1;
	char item_name[20];
	int n;
	int amt;
	int phoneno;
	if((new2=(t*)calloc(1,sizeof(t)))==NULL)
	{
		printf("Memory Alocation Failed");
		return EXIT_FAILURE;
	}
	printf("------WELCOME TO THE ONLINE DELIVERY SYSTEM------");
	printf("\n\nEnter your name-");
	scanf("%s",c1.customerName);
	printf("Enter the phone num-");
	while(1)
	{
		scanf("%lld",&new2->custphoneno);
		for(ptr1=start1;(ptr1);ptr1=ptr1->next1)
		{
			if(ptr1->cphoneno!=new2->custphoneno)
			{
				printf("Enter valid phone number.");
				continue;
			}
			else
			{
				printf("Phone number verification has been successful\n");
				printf("---Start the ordering---\n");
				break;
			}
		}
		break;
	}
	printf("\n--------------------------------------------\n");
	printf("Enter number of items you want to order-");
	while(1)
	{
		scanf("%d",&n);
		if(n<1 || n>3)
		{
			printf("enter the items between 1-3\n");
			continue;
		}
		else
			break;
		break;
	}
	new2->num=n;
	new2->total_cost=0;
	for(int i=0;i<n;i++)
	{
		while(1)
		{
			printf("Enter the item name you want to order-");
			scanf("%s",new2->product[i]);
			for(ptr=start;(ptr);ptr=ptr->next)
			{
				for(int i=0;i<n;i++)
				{
					if(strcmp(ptr->item[i],new2->product[i])==0)
					{
						printf("\nProductid         Name    Item     quantity    Unit_Price\n\n");
						printf("%lld     %4s    %5s     %4d    %4d\n",ptr->productid,ptr->productName,ptr->item[i],ptr->quantity[i],ptr->price[i]);
					}
					break;
				}
			}
			printf("\n Enter the productid number of whose product you want to buy-");
			scanf("%lld",&new2->tproductid);
			for(ptr=start;(ptr);ptr=ptr->next)
			{
				for(int i=0;i<n;i++)
				{
					if((ptr->productid==new2->tproductid) && (strcmp(ptr->item[i],new2->product[i])==0))
					{
						new2->amount[0]=0;
						printf("Enter the quantity you want to buy-");
						scanf("%d",&new2->qty);
						new2->cost[i]=ptr->price[i];
						new2->amount[i]=new2->amount[i]+(new2->qty*ptr->price[i]);
						ptr->quantity[i]=ptr->quantity[i]-new2->qty;
						printf("Total price is-%d\n",new2->amount[i]);
					}

				}
			}
			break;
		}

		new2->total_cost=new2->total_cost+new2->amount[i];

		printf("Total price of the items-%d\n",new2->total_cost);
		printf("Enter the amount to pay: ");
		scanf("%d",&amt);
		if(new2->total_cost==amt)
		{
			printf("\nYour Transaction is Successfull.\n");
		}
	}
	if(!start2)
	{
		start2=new2;
		new2->next2=NULL;
	}
	else if(new2->custphoneno < start2->custphoneno)
	{
		new2->next2=start2;
		start2=new2;
	}
	else
	{
		for(ptr2=start2;(ptr2) && ptr2->custphoneno<new2->custphoneno;prev2=ptr2,ptr2=ptr2->next2);
		prev2->next2=new2;
		new2->next2=ptr2;
	}

	return EXIT_FAILURE;

}

/*******************************************************************************************
 *
 *   *FUNCTION NAME  :  edit_customer_details
 *
 *   *DESCRIPTION    :  This functions is used here to edit the datas of the customer by the customer
 *                        or by the Admin after the registration process.
 *
 *   *RETURNS        :  No Returns
 *
 *******************************************************************************************/


int edit_customer_details()
{
	if(!start1)
	{
		printf("\n Empty List\n");
		return EXIT_FAILURE;
	}
	long long int phno;
	while(1)
	{
		printf("\nEnter phone number for editing-");
		scanf("%lld",&phno);
		if(validate_phoneno(phno))
			continue;
		break;
	}
	for(ptr1=start1;(ptr1) && ptr1->cphoneno!=phno;ptr1=ptr1->next1);
	if(!ptr1)
	{
		printf("\n Phone number %lld not found\n",phno);
		return EXIT_FAILURE;
	}
/*	printf("\nOld name is %s and phonenum is %lld\n",ptr1->customerName,ptr1->cphoneno);
	printf("\nEnter new name-");
	scanf("%s",&ptr1->customerName);
	while(1)
	{
		printf("\nEnternew  phone number -");
		scanf("%lld",&ptr1->cphoneno);

		if(validate_phoneno(tphoneno))
			continue;
		break;
	}
	return EXIT_SUCCESS;*/
	printf("Old name is %s/n",ptr1->customerName);
	printf("Enter new name ");
	scanf("%s",ptr1->customerName);
	return EXIT_SUCCESS;
}
/*******************************************************************************************
 *
 *   *FUNCTION NAME  :  show_customer_details
 *
 *   *DESCRIPTION    :  This functions is used here to displays the datas of the customers by the customer
 *                        or by the Admin.
 *
 *   *RETURNS        :  No Returns
 *
 *******************************************************************************************/



int show_customer_details()
{
	if(!start1)
	{
		printf("\nEmpty List\n");
		system("read a");
		system("clear");
		return EXIT_FAILURE;
	}
	
	printf("\n NAME          PHONENUM         ADDRESS   \n");
	for(ptr1=start1;(ptr1);ptr1=ptr1->next1)
	{
		printf("\n%2s      %3lld       %3s   ",ptr1->customerName,ptr1->cphoneno,ptr1->address);



	}
	system("read a");
	system("clear");
	return EXIT_SUCCESS;
}
/*******************************************************************************************
 *
 *   *FUNCTION NAME  :  delete customer data
 *
 *   *DESCRIPTION    :  This functions is used here to delete the data of the customer by the Admin.
 *
 *   *RETURNS        :  No Returns
 *
 *******************************************************************************************/


int delete_customer_data()
{
	if(!start1)
	{
		printf("\nThe List is Empty\n");
		return EXIT_FAILURE;
	}
	int aphoneno;
	while(1)
	{
		printf("\nEnter the Phoneno for deleting-");
		scanf("%d",&aphoneno);
		if(validate_phoneno(aphoneno))
			continue;
		break;
	}
	if(aphoneno==start1->cphoneno)
	{
		ptr1=start1;
		start1=start1->next1;
		free(ptr1);
	}
	else
	{
		for(ptr1=start1;(ptr1) && ptr1->cphoneno!=aphoneno;prev1=ptr1,ptr1=ptr1->next1);
		if(!ptr1)
		{
			printf("\nPhoneNo %d is not found\n",aphoneno);
			return EXIT_FAILURE;
		}
		prev1->next1=ptr1->next1;
		free(ptr1);
	}
	return EXIT_SUCCESS;
}

/*******************************************************************************************
 *
 *   *FUNCTION NAME  :  customer_to_list
 *
 *   *DESCRIPTION    :  This functions is used here to transfer the datas from the customer file  
 *                           to the list.
 *   *RETURNS        :  No Returns
 *
 *******************************************************************************************/


int customer_to_list()
{
	FILE *cp;
	ctt c1;
	if((cp=fopen("../data/Customer.data","rb"))==NULL)
	{
		printf("\nFile is not present to read from\n");
		return EXIT_FAILURE;
	}
	system("clear");
	fread(&c1,sizeof(ctt),1,cp);
	while(!feof(cp))
	{
		if((new1=(ct *)calloc(1,sizeof(ct)))==NULL)
		{
			printf("\nMemory Allocation failed\n");
			return EXIT_FAILURE;
		}


		new1->cphoneno=c1.cphoneno;
		strcpy(new1->customerName, c1.customerName);
		
		strcpy(new1->address,c1.address);
		/*if(!start1)
		{
			start1 = last1 = new1;
			new1->next1=NULL;
		}
		else
		{
			last1->next1=new1;
			last1=new1;
			new1->next1=NULL;
		}*/
		fread(&c1,sizeof(ctt),1,cp);
	}
	//free(new1);
	fclose(cp);
	return EXIT_SUCCESS;

}

/*******************************************************************************************
 *
 *   *FUNCTION NAME  :  list_customer
 *
 *   *DESCRIPTION    :  This functions is used here to transfer the datas of the customer from 
 *                           the list to the customer file.
 *
 *   *RETURNS        :  No Returns
 *
 *******************************************************************************************/

int list_to_customer()                                        //list to customer function starts here....
{
	ctt c2;
	if(!start1)
	{
		printf("\nThe List is Empty.\n");
		return EXIT_FAILURE;
	}
	FILE *cp1;
	if((cp1=fopen("../data/Customer.data","wb"))==NULL)
	{
		printf("\nFile is not present to read \n");
		return EXIT_FAILURE;
	}
	for(ptr1=start1;(ptr1);ptr1=ptr1->next1)
	{
		
		c2.cphoneno=ptr1->cphoneno;
		strcpy(c2.customerName,ptr1->customerName);
		strcpy(c2.address,ptr1->address);
		fwrite(&c2,sizeof(ctt),1,cp1);
	}
	fclose(cp1);
	//free(ptr1);
	return EXIT_SUCCESS;
}                                                                 //list to customer function ends here

/*******************************************************************************************
 *
 *   *FUNCTION NAME  :  product_report
 *
 *   *DESCRIPTION    :  This functions is used to generate the sales report for a particular product.
 *
 *   *RETURNS        :  No Returns
 *
 *******************************************************************************************/

int product_report()
{
	long long int aproductid;

	if(!start2)
	{
		printf("\nEmpty List\n");
		return EXIT_FAILURE;
	}
	printf("Enter the product id of an item:");
	while(1)
	{
		scanf("%lld",&aproductid);
		for(ptr2=start2;(ptr2);ptr2=ptr2->next2)
		{
			printf("\nPRODUCT ID    ITEM NAME     QUANTITY     UNIT    PRICE COST\n");
			for(int i=0;i<ptr2->num;i++)
			{
				if(ptr2->tproductid==aproductid)
				{
					printf(" %lld    %4s    %5d    %5d    %5d\n",ptr2->tproductid,ptr2->product[i],ptr2->qty,ptr2->cost[i],ptr2->amount[i]);
				}
				else
					printf("No sales from the particular product.");
				break;
			}
			break;
		}
		break;
	}

	return EXIT_SUCCESS;

}

/*******************************************************************************************
 *
 *   *FUNCTION NAME  :  consolidated_transaction_report
 *
 *   *DESCRIPTION    :  This functions is used to generate the the total transaction details
 *                          of the purchase made by customer
 *
 *   *RETURNS        :  No Returns
 *
 *******************************************************************************************/

int consolidated_transaction_report()
{
	if(!start2)
	{
		printf("\nThe List is Empty\n");
		return EXIT_FAILURE;
	}

	printf("\n PRODUCT ID    CUSTOMER NAME    ITEM NAME    QUANTITY    UNIT PRICE    AMOUNT  \n");
	for(ptr2=start2;(ptr2);ptr2=ptr2->next2)
	{
		for(int i=0;i<ptr2->num;i++)
		{
			printf("\n %lld     %lld    %3s    %3s    %3d    %3d    %3d \n",ptr2->customerName,ptr2->product[i], ptr2->qty,ptr2->cost[i],ptr2->amount[i]);
		}
		printf("\n");
	}



	return EXIT_SUCCESS;
}

/*******************************************************************
 *    *FUNCTION NAME	 : reports_menu
 *
 *    *DESCRIPTION       : This function is used to view the various reports by the admin.
 *
 *    *RETURNS           : product_report function  - For getting the reports of a particular product by the admin.
 *     			   consolidated_transaction_report function  - For viewing the consolidated report on all the purchses done till then by the admin.
 *     			   back  - To go back to the main menu.
 *
 *******************************************************************/


int reports_menu()
{
	int ch=0;
	system("clear");
	while(ch!=3)
	{
		printf("\n");
		printf("\n-------------  WELCOME ADMIN TO REPORT MENU   -------------------\n");
		printf("\n1.product report\n2.transcation report\n3.back\n");
		printf("\nEnter choice-");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: product_report();
				break;
			case 2: consolidated_transaction_report();
				break;
			case 3: break;
			default: printf("Invalid choice");
		}
		system("read a");
		system("clear");
	}
	return EXIT_SUCCESS;
}

/*******************************************************************************************
 *
 *   *FUNCTION NAME  :  transaction to list
 *
 *   *DESCRIPTION    :  This functions is used here to transfer the datas of the transactions from
 *                           the transaction file to the list.
 *
 *   *RETURNS        :  No Returns
 *
 *******************************************************************************************/

int transaction_to_list()
{
	FILE *pr;
	tt p1;
	if((pr=fopen("../data/Transaction.data","rb"))==NULL)
	{
		printf("\nFile is not there to read from\n");
		return EXIT_FAILURE;
	}
	fread(&p1,sizeof(tt),1,pr);
	while(!feof(pr))
	{
		if((new2=(t *)calloc(1,sizeof(t)))==NULL)
		{
			printf("\nMemory Allocation failed\n");
			return EXIT_FAILURE;
		}
		new2->tproductid=p1.tproductid;
		new2->custphoneno=p1.custphoneno;
		new2->num=p1.num;
		for(int i=0;i<new2->num;i++)
		{
			strcpy(new2->product[i],p1.product[i]);
			new2->quantity2[i]=p1.quantity2[i];
			new2->cost[i]=p1.cost[i];
			new2->amount[i]=p1.amount[i];
		}
		new2->total_cost=p1.total_cost;
		if(!start2)
		{
			start2 = last2 = new2;
			new2->next2=NULL;
		}
		else
		{
			last2->next2=new2;
			last2=new2;
			new2->next2=NULL;
		}
		fread(&p1,sizeof(tt),1,pr);
	}
	free(new2);
	fclose(pr);
	return EXIT_SUCCESS;
}
/*******************************************************************************************
 *
 *   *FUNCTION NAME  :  list_to_transaction
 *
 *   *DESCRIPTION    :  This functions is used here to transfer the datas of the transactions from 
 *                           the list to the transactiion file.
 *
 *   *RETURNS        :  No Returns
 *
 *******************************************************************************************/

int list_to_transaction()
{
	tt p2;
	if(!start2)
	{
		printf("\nThe List is Empty.\n");
		return EXIT_FAILURE;
	}
	FILE *pr;
	if((pr=fopen("../data/Transaction.data","wb"))==NULL)
	{
		printf("\nFile is not there to read from\n");
		return EXIT_FAILURE;
	}
	for(ptr2=start2;(ptr2);ptr2=ptr2->next2)
	{
		p2.tproductid=ptr2->tproductid;
		p2.custphoneno=ptr2->custphoneno;
		p2.num=ptr2->num;
		for(int i=0;i<p2.num;i++)
		{
			strcpy(p2.product[i],ptr2->product[i]);
			p2.quantity2[i]=ptr2->quantity2[i];
			p2.cost[i]=ptr2->cost[i];
			p2.amount[i]=ptr2->amount[i];
		}
		p2.total_cost=ptr2->total_cost;

		fwrite(&p2,sizeof(tt),1,pr);
	}
	fclose(pr);
	free(ptr2);
	return EXIT_SUCCESS;

}





