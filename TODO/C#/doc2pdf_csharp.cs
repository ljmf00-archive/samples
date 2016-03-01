using Microsoft.VisualBasic;
using System;
using System.Collections;
using System.Collections.Generic;
using System.Data;
using System.Diagnostics;
using System.Windows;
using Microsoft.Office.Interop.Word;
using System.Windows.Forms;

public class doc2pdf
{

	private void doc2pdf_Load(object sender, EventArgs e)
	{
		Console.WriteLine(System.DateTime.Now.ToString + "> " + "Open DOC2PDF converter");
	}

	private void Button1_Click(object sender, EventArgs e)
	{
		Console.WriteLine(System.DateTime.Now.ToString + "> " + "Open File Dialog");
		OpenFileDialog dlg = new OpenFileDialog();

		// Set filter for file extension and default file extension
		dlg.DefaultExt = ".doc";
		dlg.Filter = "Word documents (.doc)|*.docx;*.doc";

		// Display OpenFileDialog by calling ShowDialog method
		Nullable<bool> result = dlg.ShowDialog();

		// Get the selected file name and display in a TextBox
		if (result == true) {
			// Open document
			string filename = dlg.FileName;
			TextBox1.Text = filename;
		}
	}

	private void Button2_Click(object sender, EventArgs e)
	{
		Console.WriteLine(System.DateTime.Now.ToString + "> " + "Converting");
		Microsoft.Office.Interop.Word.Application appWord = new Microsoft.Office.Interop.Word.Application[];
		wordDocument = appWord.Documents.Open(TextBox1.Text);
		Console.WriteLine(System.DateTime.Now.ToString + "> " + "Open Save dialog");
		SaveFileDialog sfd = new SaveFileDialog();
		sfd.Filter = "PDF Documents|*.pdf";
		try {
			if (sfd.ShowDialog() == System.Windows.Forms.DialogResult.OK) {
				string ext = System.IO.Path.GetExtension(sfd.FileName);
				switch (ext) {
					case ".pdf":
						wordDocument.ExportAsFixedFormat(sfd.FileName, WdExportFormat.wdExportFormatPDF);
						TextBox2.Text = sfd.FileName;
						break; // TODO: might not be correct. Was : Exit Select

						break;
					//case ".docx":
					//    wordDocument.ExportAsFixedFormat(sfd.FileName, WdExportFormat.wdExportFormatPDF);
					//    break;
				}
			}
			Console.WriteLine(System.DateTime.Now.ToString + "> " + "Converted");
			System.Windows.Forms.MessageBox.Show("File Converted Successfully..");
		} catch (Exception ex) {
			System.Windows.Forms.MessageBox.Show(ex.Message);
		}
		Console.WriteLine(System.DateTime.Now.ToString + "> " + "Open file with Precces.Start");
		System.Diagnostics.Process.Start(sfd.FileName);
	}
	public Microsoft.Office.Interop.Word.Document wordDocument {
		get { return m_wordDocument; }
		set { m_wordDocument = value; }
	}
	private Microsoft.Office.Interop.Word.Document m_wordDocument;
	public doc2pdf()
	{
		Load += doc2pdf_Load;
	}
}