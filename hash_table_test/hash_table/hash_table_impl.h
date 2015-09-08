template <size_t S, typename K, typename T>
HashTable <S,K,T> :: HashTable ()
{
	hashTable_ = new cell [S];
	
	for (size_t count = 0; count < S; count++)
		hashTable_[count].status = "Empty"; 
}

template <size_t S, typename K, typename T>
HashTable <S,K,T> :: HashTable (const HashTable& copy)
{
	hashTable_ = new cell [S];
	
	for (size_t count = 0; count < S; count++) 
		hashTable_[count] = copy.hashTable_[count];
}

template <size_t S, typename K, typename T>
HashTable <S,K,T> :: ~HashTable ()
{
	delete [] hashTable_;
}

template <size_t S, typename K, typename T>
HashTable <S,K,T>& HashTable <S,K,T> :: operator = (const HashTable& leftValue)
{
	if (this != &leftValue) 
		for (size_t count = 0; count < S; count++) 
			hashTable_[count] = leftValue.hashTable_[count];
	
	return* this;
}

template <size_t S, typename K, typename T>
void HashTable <S,K,T> :: printHashTable (string fileName)
{
	ofstream saveFile (fileName);
	saveFile << "[index] = (status) <key, [data]>\n";

	for (size_t count = 0; count < S; count++) {
		saveFile << "[" << count << "] (" << hashTable_[count].status << ") <(" << hashTable_[count].key << "), [" << hashTable_[count].data << "]>\n";
	}

	saveFile.close();
}

template <size_t S, typename K, typename T>
int HashTable <S,K,T> :: hashFunction (K key)
{
	const double A = (sqrt(5) - 1)/2; 
	hash<K> hash; 
	return floor(S*(hash(key)*A - floor(hash(key)*A)));
}

template <size_t S, typename K, typename T>
int HashTable <S,K,T> :: linearInvestigation (K key, size_t count)
{
	return (hashFunction(key) + count) % S;
}

template <size_t S, typename K, typename T>
bool HashTable <S,K,T> :: hashTable_Insert (K key, T data)
{
	size_t count (0), index(0);	

	do
	{
		index = linearInvestigation (key, count);
		
		if (hashTable_[index].status != "Busy") 
		{
			hashTable_[index].status = "Busy";
			hashTable_[index].key = key;
			hashTable_[index].data = data;

			return true;
		}
		else count++;
	}
	while (count != S);

	return false;
}
 
template <size_t S, typename K, typename T>
int HashTable <S,K,T> :: hashTable_Search (K key)
{
	int index(0), count(0);
	
	do
	{
		index = linearInvestigation (key, count);		
		if (hashTable_[index].status != "Delete")
		{
			if (hashTable_[index].key == key) 
				return index;
		}
		count++;
	}
	while (hashTable_[index].status != "Empty" && count != S);

	return -1;
}

template <size_t S, typename K, typename T>
void HashTable <S,K,T> :: hashTable_Remove (int i)
{
	if (hashTable_[i].status != "Empty")
	{
		//R1 
		hashTable_[i].status = "Delete";
		int j(i);
		bool ifNeedR4(true);
		
		while (true)
		{
			//R2
			i = i - 1;
			if (i < 0) 
				i = i + S;
			
			//R3 
			if (hashTable_[i].status == "Delete")
				break;
			else 
			{
				size_t r = hashFunction (hashTable_[i].key);
				if (i <= r && r < j) ifNeedR4 = false;
				else if ((r < j && j < i) || (j < i && j <= r))  
					ifNeedR4 = false;
			}
		
			//R4
			if (ifNeedR4 == true) hashTable_[j] = hashTable_[i];
		}
	}
}

template <size_t S, typename K, typename T>
T HashTable <S,K,T> :: getCellData (size_t index)
{
	return hashTable_[index].data;
}

template <size_t S, typename K, typename T>
K HashTable <S,K,T> :: getCellKey (size_t index)
{
	return hashTable_[index].key;
}

template <size_t S, typename K, typename T>
string HashTable <S,K,T> :: getCellStatus (size_t index)
{
	return hashTable_[index].status;
}