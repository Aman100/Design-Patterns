/*
Adapter Pattern: This pattern is used in scenario when one entity needs to access
services of another but there is no compatibality between them.
Adapter (Converter) would be require to establish compatibality

Scenario:
Need to convert image file to pdf and then upload to it.
DocumentUploader: Responsible for uploading document.
ImageFile: Contains information regarding image type, image path.

Where to convert Image to PDF? It's can't be in ImageFile. ImageFile only 
responsibility is to store imageType, imagePath

Then where?
Created an Adapter which is responsible for converting image to PDF after 
validating information then call DocumentUploader's uploadDocument method to 
upload document.

If in future we would require to upload word document after converting it then
same as image file we need to do necessary validations then convert word document
to pdf place a call to upload document.
*/

#include<iostream>
using namespace std;

//guideline
class UploadableDocument
{
public:
virtual string getPdfFilePath()=0;
};

//Designer of DocumentUploader class is creating a guideline which specify that 
//DocumentUploader is only compatible with document of type PDF, means implementor
//of guideline can only works with PDF.
class DocumentUploader
{
public:
bool uploadDocument(UploadableDocument *uploadableDocument)
{
string pdfFilePath=uploadableDocument->getPdfFilePath();
/*
Network programming code to upload PDFDocument to target Location
*/
return true;
}
};

class PDFDocument:public UploadableDocument
{
private:
string filePath;
public:
PDFDocument(string filePath)
{
this->filePath=filePath;
}
string getFilePath()
{
return this->filePath;
}
string getPdfFilePath()
{
return getFilePath();
}
};

//guideline
class Document
{
public:
virtual string getType()=0;
virtual string getPath()=0;
};

//Designer of DocumentUploadAdapter is creating a guideline which specify that
//implementor of guideline should specify type, path of image file
class DocumentUploadAdapter
{
private:
Document *document;
DocumentUploader *documentUploader;
public:
DocumentUploadAdapter(DocumentUploader *documentUploader, Document *document)
{
this->documentUploader=documentUploader;
this->document=document;
}
bool uploadDocument()
{
string filePath=document->getPath();
string fileType=document->getType();
if(fileType!="PDF")
{
/*
Check if the type of document are
1. JPG
2. PNG
3. BMP
if Yes:
	then convert this image to document of type PDF and set new path in filePath
*/
}
PDFDocument pdfDocument(filePath);
return documentUploader->uploadDocument(&pdfDocument);
}
};

class ImageFile:public Document
{
private:
string filePath;
string fileType;
public:
ImageFile(string filePath, string fileType):filePath(filePath),fileType(fileType)
{
}
string getType()
{
return this->fileType;
}
string getPath()
{
return this->filePath;
}
};

int main()
{
ImageFile imageFile("http://localhost:8080/abc/log.jpg","JPG");
DocumentUploader documentUploader;
DocumentUploadAdapter documentUploadAdapter(&documentUploader, &imageFile);
if(documentUploadAdapter.uploadDocument())cout<<"Document uploaded"<<endl;
else cout<<"Unable to upload document"<<endl;
}
