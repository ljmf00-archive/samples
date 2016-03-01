using System.IO;
using Microsoft.Office.Interop.Word;

namespace totalLibrary.Converters
{
    public class Doctopdf
    {
        Microsoft.Office.Interop.Word.Application _Word = new Microsoft.Office.Interop.Word.Application();
        object _MissingValue = System.Reflection.Missing.Value;
        public void PDFfromDOC(string wordFileName, out string pdfFileName)
        {
            _Word.Visible = false;
            _Word.ScreenUpdating = false;
            object filename = (object)wordFileName;
            Document doc = _Word.Documents.Open(ref filename, ref _MissingValue,
             ref _MissingValue, ref _MissingValue, ref _MissingValue, ref _MissingValue, ref _MissingValue,
             ref _MissingValue, ref _MissingValue, ref _MissingValue, ref _MissingValue, ref _MissingValue,
             ref _MissingValue, ref _MissingValue, ref _MissingValue, ref _MissingValue);
            doc.Activate();

            object outputFileName = pdfFileName = Path.ChangeExtension(wordFileName, "pdf");
            object fileFormat = WdSaveFormat.wdFormatPDF;
            doc.SaveAs(ref outputFileName,
             ref fileFormat, ref _MissingValue, ref _MissingValue,
             ref _MissingValue, ref _MissingValue, ref _MissingValue, ref _MissingValue,
             ref _MissingValue, ref _MissingValue, ref _MissingValue, ref _MissingValue,
             ref _MissingValue, ref _MissingValue, ref _MissingValue, ref _MissingValue);
            object saveChanges = WdSaveOptions.wdDoNotSaveChanges;
            ((_Document)doc).Close(ref saveChanges, ref _MissingValue, ref _MissingValue);
            doc = null;
            ((_Application)_Word).Quit(ref _MissingValue, ref _MissingValue, ref _MissingValue);
            _Word = null;
        }
    }
}
