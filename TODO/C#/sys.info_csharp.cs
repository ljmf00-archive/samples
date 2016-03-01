using Microsoft.VisualBasic;
using System;
using System.Collections;
using System.Collections.Generic;
using System.Data;
using System.Diagnostics;
using System.Management;
using System.Environment;
using System.Text;

public class systeminfo
{
	private string SystemInformation()
	{
		StringBuilder StringBuilder1 = new StringBuilder(string.Empty);
		try {
			StringBuilder1.AppendFormat("Operation System:  {0}" + Constants.vbLf, Environment.OSVersion);
			if (Environment.Is64BitOperatingSystem) {
				StringBuilder1.AppendFormat(Constants.vbTab + Constants.vbTab + "  64 Bit Operating System" + Constants.vbLf);
			} else {
				StringBuilder1.AppendFormat(Constants.vbTab + Constants.vbTab + "  32 Bit Operating System" + Constants.vbLf);
			}
			StringBuilder1.AppendFormat("SystemDirectory:  {0}" + Constants.vbLf, Environment.SystemDirectory);
			StringBuilder1.AppendFormat("ProcessorCount:  {0}" + Constants.vbLf, Environment.ProcessorCount);
			StringBuilder1.AppendFormat("UserDomainName:  {0}" + Constants.vbLf, Environment.UserDomainName);
			StringBuilder1.AppendFormat("UserName: {0}" + Constants.vbLf, Environment.UserName);
			//Drives
			StringBuilder1.AppendFormat("LogicalDrives:" + Constants.vbLf);
			foreach (System.IO.DriveInfo DriveInfo1 in System.IO.DriveInfo.GetDrives()) {
				try {
					StringBuilder1.AppendFormat(Constants.vbTab + " Drive: {0}" + Constants.vbLf + Constants.vbTab + Constants.vbTab + " VolumeLabel: " + "{1}" + Constants.vbLf + Constants.vbTab + Constants.vbTab + " DriveType: {2}" + Constants.vbLf + Constants.vbTab + Constants.vbTab + " DriveFormat: {3}" + Constants.vbLf + Constants.vbTab + Constants.vbTab + " " + "TotalSize: {4}" + Constants.vbLf + Constants.vbTab + Constants.vbTab + " AvailableFreeSpace: {5}" + Constants.vbLf, DriveInfo1.Name, DriveInfo1.VolumeLabel, DriveInfo1.DriveType, DriveInfo1.DriveFormat, DriveInfo1.TotalSize, DriveInfo1.AvailableFreeSpace);
				} catch {
				}
			}
			StringBuilder1.AppendFormat("SystemPageSize:  {0}" + Constants.vbLf, Environment.SystemPageSize);
			StringBuilder1.AppendFormat("Version:  {0}", Environment.Version);
		} catch {
		}
		return StringBuilder1.ToString();
	}

	private string DeviceInformation(string stringIn)
	{
		StringBuilder StringBuilder1 = new StringBuilder(string.Empty);
		ManagementClass ManagementClass1 = new ManagementClass(stringIn);
		//Create a ManagementObjectCollection to loop through
		ManagementObjectCollection ManagemenobjCol = ManagementClass1.GetInstances();
		//Get the properties in the class
		PropertyDataCollection properties = ManagementClass1.Properties;
		foreach (ManagementObject obj in ManagemenobjCol) {
			foreach (PropertyData property in properties) {
				try {
					StringBuilder1.AppendLine(property.Name + ":  " + obj.Properties(property.Name).Value.ToString());
					//Add codes to manage more informations
				} catch {
				}
			}
			StringBuilder1.AppendLine();
		}
		return StringBuilder1.ToString();
	}
	private void systeminfo_Load(object sender, EventArgs e)
	{
		//System Information
		RichTextBox1.Text = SystemInformation();
		//CPU Information
		RichTextBox2.Text = DeviceInformation("Win32_Processor");
		//Local Drives Information
		RichTextBox4.Text = DeviceInformation("Win32_LogicalDisk");
		//Video Controller Information
		RichTextBox3.Text = DeviceInformation("Win32_VideoController");
	}
	public systeminfo()
	{
		Load += systeminfo_Load;
	}
}