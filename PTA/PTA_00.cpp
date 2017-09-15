List Merge(List L1, List L2)
{
	List L = (List)malloc(sizeof(List));
	L->Next = NULL;
	PtrToNode head = L;
	PtrToNode ptr1 = L1, ptr2 = L2;
	L1 = ptr1->Next;
	L2 = ptr2->Next;
	ptr1->Next = NULL;
	ptr2->Next = NULL;
	while (L1&&L2)
	{
		if (L1->Data < L2->Data)
		{
			head->Next = L1;
			L1 = L1->Next;
			head = head->Next;
		}
		else
		{
			head->Next = L2;
			L2 = L2->Next;
			head = head->Next;
		}
	}
	while (L1)
	{
		head->Next = L1;
		L1 = L1->Next;
		head = head->Next;
	}
	while (L2)
	{
		head->Next = L2;
		L2 = L2->Next;
		head = head->Next;
	}
	head->Next = NULL;
	return L;
}