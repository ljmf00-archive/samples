using System;
using System.Diagnostics;
using System.Management;
using System.Text;

namespace totalLibrary.SystemInfo
{
    class ProcessManagement
    {
        public static string ListAllProcesses()
        {
            StringBuilder sb = new StringBuilder();

            // list out all processes and write them into a stringbuilder
            ManagementClass MgmtClass = new ManagementClass("Win32_Process");

            foreach (ManagementObject mo in MgmtClass.GetInstances())
            {
                sb.Append("Name:\t" + mo["Name"] + Environment.NewLine);
                sb.Append("ID:\t" + mo["ProcessId"] + Environment.NewLine);
                sb.Append(Environment.NewLine);
            }

            return sb.ToString();
        }
        public static string ListAllApplications()
        {
            StringBuilder sb = new StringBuilder();

            foreach (Process p in Process.GetProcesses("."))
            {
                try
                {
                    if (p.MainWindowTitle.Length > 0)
                    {
                        sb.Append("Window Title:\t" + p.MainWindowTitle.ToString() + Environment.NewLine);
                        sb.Append("Process Name:\t" + p.ProcessName.ToString() + Environment.NewLine);
                        sb.Append("Window Handle:\t" + p.MainWindowHandle.ToString() + Environment.NewLine);
                        sb.Append("Memory Allocation:\t" + p.PrivateMemorySize64.ToString() + Environment.NewLine);
                        sb.Append(Environment.NewLine);
                    }
                }
                catch { }
            }

            return sb.ToString();
        }
        public static string ListAllByImageName()
        {

            StringBuilder sb = new StringBuilder();

            foreach (Process p in Process.GetProcesses("."))
            {
                try
                {
                    foreach (ProcessModule pm in p.Modules)
                    {
                        sb.Append("Image Name:\t" + pm.ModuleName.ToString() + Environment.NewLine);
                        sb.Append("File Path:\t\t" + pm.FileName.ToString() + Environment.NewLine);
                        sb.Append("Memory Size:\t" + pm.ModuleMemorySize.ToString() + Environment.NewLine);
                        sb.Append("Version:\t\t" + pm.FileVersionInfo.FileVersion.ToString() + Environment.NewLine);
                        sb.Append(Environment.NewLine);
                    }
                }
                catch { }
            }

            return sb.ToString();
        }
        public static bool CheckForProcessByName(string processName)
        {

            ManagementClass MgmtClass = new ManagementClass("Win32_Process");
            bool rtnVal = false;

            foreach (ManagementObject mo in MgmtClass.GetInstances())
            {
                if (mo["Name"].ToString().ToLower() == processName.ToLower())
                {
                    rtnVal = true;
                }
            }

            return rtnVal;
        }
        public static bool CheckForProcessByImageName(string processImageName)
        {

            bool rtnVal = false;

            foreach (Process p in Process.GetProcesses("."))
            {
                try
                {
                    foreach (ProcessModule pm in p.Modules)
                    {
                        if (pm.ModuleName.ToLower() == processImageName.ToLower())
                            rtnVal = true;
                    }
                }
                catch { }
            }

            return rtnVal;
        }
        public static bool CheckForApplicationByName(string AppName)
        {
            bool bRtn = false;

            foreach (Process p in Process.GetProcesses("."))
            {
                try
                {
                    if (p.ProcessName.ToString().ToLower() == AppName.ToLower())
                    {
                        bRtn = true;
                    }
                }
                catch { }
            }

            return bRtn;
        }
        public static bool FindProcessById(string processId)
        {
            ManagementClass MgmtClass = new ManagementClass("Win32_Process");
            bool rtnVal = false;

            foreach (ManagementObject mo in MgmtClass.GetInstances())
            {
                if (mo["ProcessId"].ToString() == processId)
                {
                    rtnVal = true;
                }
            }

            return rtnVal;
        }
    }
}
