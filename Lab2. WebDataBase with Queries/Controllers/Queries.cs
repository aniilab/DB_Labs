using Microsoft.AspNetCore.Mvc;
using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc.Rendering;
using Microsoft.Data.SqlClient;
using Microsoft.EntityFrameworkCore;
using MovieBase.Models;
using ClosedXML.Excel;

namespace MovieBase.Controllers
{
    public class QueriesController : Controller
    {
        private const string CONNECTION_STRING = "Server=ALINA;Database=DBMoviesSQL;Trusted_Connection=True;MultipleActiveResultSets=true";
        private const string ERR = "Немає результатів для даного запиту";
        private const string DEFAULT_PATH = @"D:\c#\MovieBase\MovieBase\Queries\";
        private readonly DBMoviesSQLContext _context;
        private List<string> temp = new List<string>();

        public QueriesController(DBMoviesSQLContext context)
        {
            _context = context;
        }
        public IActionResult Index(int errorCode)
        {
            var actors = _context.Actors.Select(a => a.Name).Distinct().ToList();

            ViewBag.ActorsList = new SelectList(_context.Actors, "Name", "Name");
            ViewBag.GenresList = new SelectList(_context.Genres, "Name", "Name");
            ViewBag.MoviesList = new SelectList(_context.Movies, "Name", "Name");
            ViewBag.DirectorsList = new SelectList(_context.Directors, "Name", "Name");
            ViewBag.ProductionsList = new SelectList(_context.Productions, "Name", "Name");
            if (errorCode == 1) ViewBag.Error1 = "Недопустиме значення";
            if (errorCode == 2) ViewBag.Error2 = "Недопустиме значення";
            if (errorCode == 3) ViewBag.Error3 = "Недопустиме значення";
            if (errorCode == 4) ViewBag.Error4 = "Недопустиме значення";
            if (errorCode == 5) ViewBag.Error5 = "Недопустиме значення";
            return View();
        }

        public IActionResult Result(Query queryResult)
        {
            ViewBag.CurrentProduction = queryResult.ProductionName;
            return View(queryResult);
        }

        [HttpPost]
        [ValidateAntiForgeryToken]
        public IActionResult SimpleQuery1(Query queryModel)
        {
            string query = System.IO.File.ReadAllText(DEFAULT_PATH + "SIMPLE_QUERY_1.sql");
            query = query.Replace("ActorName", "N\'" + queryModel.ActorName + "\'");
            query = query.Replace("\r\n", " ");
            query = query.Replace('\t', ' ');

            queryModel.QueryId = "S1";
            queryModel.MoviesNames = new List<string>();

            using (var connection = new SqlConnection(CONNECTION_STRING))
            {
                connection.Open();
                using (var command = new SqlCommand(query, connection))
                {
                    command.ExecuteNonQuery();
                    using (var reader = command.ExecuteReader())
                    {
                        int flag = 0;
                        while (reader.Read())
                        {
                            queryModel.MoviesNames.Add(reader.GetString(0));
                            flag++;
                        }
                        if (flag == 0)
                        {
                            queryModel.ErrorFlag = 1;
                            queryModel.Error = ERR;
                        }
                    }

                }
                connection.Close();
            }
            return RedirectToAction("Result", queryModel);
        }

        [HttpPost]
        [ValidateAntiForgeryToken]
        public IActionResult SimpleQuery2(Query queryModel)
        {
            string query = System.IO.File.ReadAllText(DEFAULT_PATH + "SIMPLE_QUERY_2.sql");
            query = query.Replace("GenreName", "N\'" + queryModel.GenreName + "\'");
            query = query.Replace("MovieYear", queryModel.MovieYear.ToString());
            query = query.Replace("\r\n", " ");
            query = query.Replace('\t', ' ');

            queryModel.QueryId = "S2";
            queryModel.MoviesNames = new List<string>();
            queryModel.MoviesYears = new List<int>();
            using (var connection = new SqlConnection(CONNECTION_STRING))
            {
                connection.Open();
                using (var command = new SqlCommand(query, connection))
                {
                    command.ExecuteNonQuery();
                    using (var reader = command.ExecuteReader())
                    {
                        int flag = 0;
                        while (reader.Read())
                        {
                            queryModel.MoviesNames.Add(reader.GetString(0));
                            queryModel.MoviesYears.Add(reader.GetInt32(1));
                            flag++;
                        }
                        if (flag == 0)
                        {
                            queryModel.ErrorFlag = 1;
                            queryModel.Error = ERR;
                        }
                    }

                }
                connection.Close();
            }
            return RedirectToAction("Result", queryModel);
        }

        [HttpPost]
        [ValidateAntiForgeryToken]
        public IActionResult SimpleQuery3(Query queryModel)
        {
            string query = System.IO.File.ReadAllText(DEFAULT_PATH + "SIMPLE_QUERY_3.sql");
            query = query.Replace("CountOfGenres", queryModel.CountOfGenres.ToString());
            query = query.Replace("\r\n", " ");
            query = query.Replace('\t', ' ');

            queryModel.QueryId = "S3";
            queryModel.MoviesNames = new List<string>();

            using (var connection = new SqlConnection(CONNECTION_STRING))
            {
                connection.Open();
                using (var command = new SqlCommand(query, connection))
                {
                    command.ExecuteNonQuery();
                    using (var reader = command.ExecuteReader())
                    {
                        int flag = 0;
                        while (reader.Read())
                        {
                            queryModel.MoviesNames.Add(reader.GetString(0));
                            flag++;
                        }
                        if (flag == 0)
                        {
                            queryModel.ErrorFlag = 1;
                            queryModel.Error = ERR;
                        }
                    }

                }
                connection.Close();
            }
            return RedirectToAction("Result", queryModel);
        }
        [HttpPost]
        [ValidateAntiForgeryToken]
        public IActionResult SimpleQuery4(Query queryModel)
        {
            string query = System.IO.File.ReadAllText(DEFAULT_PATH + "SIMPLE_QUERY_4.sql");
            query = query.Replace("GenreName", "N\'" + queryModel.GenreName + "\'");
            query = query.Replace("\r\n", " ");
            query = query.Replace('\t', ' ');

            queryModel.QueryId = "S4";
            queryModel.DirectorsNames = new List<string>();
            using (var connection = new SqlConnection(CONNECTION_STRING))
            {
                connection.Open();
                using (var command = new SqlCommand(query, connection))
                {
                    command.ExecuteNonQuery();
                    using (var reader = command.ExecuteReader())
                    {
                        int flag = 0;
                        while (reader.Read())
                        {
                            queryModel.DirectorsNames.Add(reader.GetString(0));
                            flag++;
                        }
                        if (flag == 0)
                        {
                            queryModel.ErrorFlag = 1;
                            queryModel.Error = ERR;
                        }
                    }

                }
                connection.Close();
            }
            return RedirectToAction("Result", queryModel);
        }
        [HttpPost]
        [ValidateAntiForgeryToken]
        public IActionResult SimpleQuery5(Query queryModel)
        {
            string query = System.IO.File.ReadAllText(DEFAULT_PATH + "SIMPLE_QUERY_5.sql");
            query = query.Replace("ProductionName", "N\'" + queryModel.ProductionName + "\'");
            query = query.Replace("\r\n", " ");
            query = query.Replace('\t', ' ');

            queryModel.QueryId = "S5";
            queryModel.GenresNames = new List<string>();

            using (var connection = new SqlConnection(CONNECTION_STRING))
            {
                connection.Open();
                using (var command = new SqlCommand(query, connection))
                {
                    command.ExecuteNonQuery();
                    using (var reader = command.ExecuteReader())
                    {
                        int flag = 0;
                        while (reader.Read())
                        {
                            queryModel.GenresNames.Add(reader.GetString(0));
                            flag++;
                        }
                        if (flag == 0)
                        {
                            queryModel.ErrorFlag = 1;
                            queryModel.Error = ERR;
                        }

                    }

                }
                connection.Close();
            }

            using (XLWorkbook workbook = new XLWorkbook(XLEventTracking.Disabled))
            {
                var worksheet = workbook.Worksheets.Add();

                worksheet.Cell("A1").Value = "Назви жанрів кіностудії " + queryModel.ProductionName;
                worksheet.Row(1).Style.Font.Bold = true;

                for (int i = 0; i < queryModel.GenresNames.Count; i++)
                {
                    worksheet.Cell(i + 2, 1).Value = queryModel.GenresNames[i];
                }
                using (var stream = new MemoryStream())
                {
                    workbook.SaveAs(stream);
                    stream.Flush();

                    return new FileContentResult(stream.ToArray(),
                        "application/vnd.openxmlformats-officedocument.spreadsheetml.sheet")
                    {

                        FileDownloadName = $"MovieBase_{DateTime.UtcNow.ToShortDateString()}.xlsx"
                    };
                }
            }
        }

        [HttpPost]
        [ValidateAntiForgeryToken]
        public IActionResult MultipleQuery1(Query queryModel)
        {
            string query = System.IO.File.ReadAllText(DEFAULT_PATH + "MULTIPLE_QUERY_1.sql");
            query = query.Replace("MovieName", "N\'" + queryModel.MovieName + "\'");
            query = query.Replace("\r\n", " ");
            query = query.Replace('\t', ' ');

            queryModel.QueryId = "M1";
            queryModel.MoviesNames = new List<string>();
            using (var connection = new SqlConnection(CONNECTION_STRING))
            {
                connection.Open();
                using (var command = new SqlCommand(query, connection))
                {
                    command.ExecuteNonQuery();
                    using (var reader = command.ExecuteReader())
                    {
                        int flag = 0;
                        while (reader.Read())
                        {
                            queryModel.MoviesNames.Add(reader.GetString(0));
                            flag++;
                        }
                        if (flag == 0)
                        {
                            queryModel.ErrorFlag = 1;
                            queryModel.Error = ERR;
                        }
                    }

                }
                connection.Close();
            }
            return RedirectToAction("Result", queryModel);
        }

        [HttpPost]
        [ValidateAntiForgeryToken]
        public IActionResult MultipleQuery2(Query queryModel)
        {
            string query = System.IO.File.ReadAllText(DEFAULT_PATH + "MULTIPLE_QUERY_2.sql");
            query = query.Replace("MovieName", "N\'" + queryModel.MovieName + "\'");
            query = query.Replace("\r\n", " ");
            query = query.Replace('\t', ' ');

            queryModel.QueryId = "M2";
            queryModel.MoviesNames = new List<string>();

            using (var connection = new SqlConnection(CONNECTION_STRING))
            {
                connection.Open();
                using (var command = new SqlCommand(query, connection))
                {
                    command.ExecuteNonQuery();
                    using (var reader = command.ExecuteReader())
                    {
                        int flag = 0;
                        while (reader.Read())
                        {
                            queryModel.MoviesNames.Add(reader.GetString(0));
                            flag++;
                        }
                        if (flag == 0)
                        {
                            queryModel.ErrorFlag = 1;
                            queryModel.Error = ERR;
                        }
                    }

                }
                connection.Close();
            }
            return RedirectToAction("Result", queryModel);
        }
        [HttpPost]
        [ValidateAntiForgeryToken]
        public IActionResult MultipleQuery3(Query queryModel)
        {
            string query = System.IO.File.ReadAllText(DEFAULT_PATH + "MULTIPLE_QUERY_3.sql");
            query = query.Replace("Rating", queryModel.Rating.ToString());
            query = query.Replace("\r\n", " ");
            query = query.Replace('\t', ' ');

            queryModel.QueryId = "M3";
            queryModel.GenresNames = new List<string>();

            using (var connection = new SqlConnection(CONNECTION_STRING))
            {
                connection.Open();
                using (var command = new SqlCommand(query, connection))
                {
                    command.ExecuteNonQuery();
                    using (var reader = command.ExecuteReader())
                    {
                        int flag = 0;
                        while (reader.Read())
                        {
                            queryModel.GenresNames.Add(reader.GetString(0));
                            flag++;
                        }
                        if (flag == 0)
                        {
                            queryModel.ErrorFlag = 1;
                            queryModel.Error = ERR;
                        }
                    }

                }
                connection.Close();
            }
            return RedirectToAction("Result", queryModel);

        }

    }
}
